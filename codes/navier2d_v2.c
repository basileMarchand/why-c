#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <tgmath.h>

#define IX(i,j) ((i) + (N+2)*(j))  // accès tableau 2D aplati

// Paramètres globaux
int N = 128;              // taille grille (N x N)
double diff = 0.0001;    // coefficient diffusion densité
double visc = 0.0001;    // viscosité fluide
double dt   = 0.1;       // pas de temps

// Masque obstacle : 1 = solide, 0 = fluide
unsigned char *solid = NULL;

// Allouer un champ (taille (N+2)x(N+2) pour bords)
double *alloc_field() {
    return calloc((N+2)*(N+2), sizeof(double));
}

unsigned char *alloc_mask() {
    return calloc((N+2)*(N+2), sizeof(unsigned char));
}

// Construire un cylindre (disque) solide de rayon r (en cellules) centré en (cx,cy) (indices grille)
void build_solid_circle(int cx, int cy, double r) {
    for (int j=0; j<=N+1; j++) {
        for (int i=0; i<=N+1; i++) {
            double dx = (double)i - cx;
            double dy = (double)j - cy;
            solid[IX(i,j)] = (dx*dx + dy*dy <= r*r) ? 1 : 0;
        }
    }
}

void build_solid_square(int x0, int y0, int x1, int y1) {
    for (int j=0; j<=N+1; j++) {
        for (int i=0; i<=N+1; i++) {
            solid[IX(i,j)] = (i>=x0 && i<=x1 && j>=y0 && j<=y1) ? 1 : 0;
        }
    }
}

// Ajouter source : x += dt * s (ignorant les cellules solides)
void add_source(double *x, double *s) {
    int size = (N+2)*(N+2);
    for (int i=0; i<size; i++) if (!solid[i]) x[i] += dt * s[i];
}

// Poser conditions aux limites (rebond simple sur bords du domaine)
void set_bnd_domain(int b, double *x) {
    for (int i=1; i<=N; i++) {
        x[IX(0,i)]   = (b==1 ? -x[IX(1,i)] : x[IX(1,i)]);
        x[IX(N+1,i)] = (b==1 ? -x[IX(N,i)] : x[IX(N,i)]);
        x[IX(i,0)]   = (b==2 ? -x[IX(i,1)] : x[IX(i,1)]);
        x[IX(i,N+1)] = (b==2 ? -x[IX(i,N)] : x[IX(i,N)]);
    }
    x[IX(0,0)]     = 0.5*(x[IX(1,0)]   + x[IX(0,1)]);
    x[IX(0,N+1)]   = 0.5*(x[IX(1,N+1)] + x[IX(0,N)]);
    x[IX(N+1,0)]   = 0.5*(x[IX(N,0)]   + x[IX(N+1,1)]);
    x[IX(N+1,N+1)] = 0.5*(x[IX(N,N+1)] + x[IX(N+1,N)]);
}

// Enforce paroi solide no-slip :
// - vitesse nulle dans l'obstacle
// - composante normale annulée dans les cellules fluides adjacentes
void enforce_obstacle_velocity(double *u, double *v) {
    for (int j=1; j<=N; j++) {
        for (int i=1; i<=N; i++) {
            int id = IX(i,j);
            if (solid[id]) { u[id]=0.0; v[id]=0.0; continue; }
            // voisins solides -> annule composante normale
            if (solid[IX(i-1,j)] || solid[IX(i+1,j)]) u[id] = 0.0;  // normal à paroi verticale
            if (solid[IX(i,j-1)] || solid[IX(i,j+1)]) v[id] = 0.0;  // normal à paroi horizontale
        }
    }
}

// Après chaque opération sur un scalaire (densité, pression intermédiaire), annule dans l'obstacle
void enforce_obstacle_scalar(double *s) {
    for (int j=1; j<=N; j++)
        for (int i=1; i<=N; i++)
            if (solid[IX(i,j)]) s[IX(i,j)] = 0.0;
}

// Jacobi iteration for diffusion/Poisson (ignore/force valeurs dans solide)
void lin_solve(int b, double *x, double *x0, double a, double c) {
    for (int k=0; k<20; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                int id = IX(i,j);
                if (solid[id]) { x[id]=0.0; continue; }
                double sum = 0.0;
                int il = IX(i-1,j), ir = IX(i+1,j), jb = IX(i,j-1), jt = IX(i,j+1);
                // Si voisin solide, on considère la valeur au centre (paroi Dirichlet), simple et stable
                double xl = solid[il] ? x[id] : x[il];
                double xr = solid[ir] ? x[id] : x[ir];
                double xb = solid[jb] ? x[id] : x[jb];
                double xt = solid[jt] ? x[id] : x[jt];
                sum = xl + xr + xb + xt;
                x[id] = (x0[id] + a * sum) / c;
            }
        }
        set_bnd_domain(b,x);
        if (b==0) enforce_obstacle_scalar(x);
    }
}

// Diffusion
void diffuse(int b, double *x, double *x0, double d) {
    double a = dt * d * N * N;
    lin_solve(b, x, x0, a, 1+4*a);
}

// Advection semi-lagrangien (bloque à/par l'obstacle)
void advect(int b, double *d, double *d0, double *u, double *v) {
    double dt0 = dt * N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int id = IX(i,j);
            if (solid[id]) { d[id]=0.0; continue; }
            double x = i - dt0 * u[id];
            double y = j - dt0 * v[id];
            if (x<0.5) x=0.5; if (x>N+0.5) x=N+0.5;
            if (y<0.5) y=0.5; if (y>N+0.5) y=N+0.5;
            int i0=(int)x, i1=i0+1;
            int j0=(int)y, j1=j0+1;
            double s1=x-i0, s0=1-s1;
            double t1=y-j0, t0=1-t1;

            // Si le point rétro-tracé tombe dans le solide, on impose 0 (pas de transport depuis l'obstacle)
            double q00 = solid[IX(i0,j0)] ? 0.0 : d0[IX(i0,j0)];
            double q01 = solid[IX(i0,j1)] ? 0.0 : d0[IX(i0,j1)];
            double q10 = solid[IX(i1,j0)] ? 0.0 : d0[IX(i1,j0)];
            double q11 = solid[IX(i1,j1)] ? 0.0 : d0[IX(i1,j1)];

            d[id] = s0*(t0*q00 + t1*q01) + s1*(t0*q10 + t1*q11);
        }
    }
    set_bnd_domain(b,d);
    if (b==0) enforce_obstacle_scalar(d);
}

// Projection (impose incompressibilité, p=0 et div=0 dans l'obstacle)
void project(double *u, double *v, double *p, double *div) {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int id = IX(i,j);
            if (solid[id]) { div[id]=0.0; p[id]=0.0; continue; }
            double du = (solid[IX(i+1,j)] ? u[id] : u[IX(i+1,j)]) - (solid[IX(i-1,j)] ? u[id] : u[IX(i-1,j)]);
            double dv = (solid[IX(i,j+1)] ? v[id] : v[IX(i,j+1)]) - (solid[IX(i,j-1)] ? v[id] : v[IX(i,j-1)]);
            div[id] = -0.5*(du + dv) / 1.0 * 1.0; // grille uniforme (pas = 1/N absorbé dans dt0)
            p[id] = 0.0;
        }
    }
    set_bnd_domain(0,div); set_bnd_domain(0,p);
    lin_solve(0,p,div,1,4);

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int id = IX(i,j);
            if (solid[id]) { u[id]=0.0; v[id]=0.0; continue; }
            double pxr = solid[IX(i+1,j)] ? p[id] : p[IX(i+1,j)];
            double pxl = solid[IX(i-1,j)] ? p[id] : p[IX(i-1,j)];
            double pyt = solid[IX(i,j+1)] ? p[id] : p[IX(i,j+1)];
            double pyb = solid[IX(i,j-1)] ? p[id] : p[IX(i,j-1)];
            u[id] -= 0.5*(pxr - pxl);
            v[id] -= 0.5*(pyt - pyb);
        }
    }
    set_bnd_domain(1,u); set_bnd_domain(2,v);
    enforce_obstacle_velocity(u,v);
}

// Step pour densité
void dens_step(double *x, double *x0, double *u, double *v) {
    add_source(x,x0);
    diffuse(0,x0,x,diff);
    advect(0,x,x0,u,v);
    enforce_obstacle_scalar(x);
}

// Step pour vitesse
void vel_step(double *u, double *v, double *u0, double *v0) {
    add_source(u,u0);
    add_source(v,v0);
    diffuse(1,u0,u,visc);
    diffuse(2,v0,v,visc);
    enforce_obstacle_velocity(u0,v0);
    project(u0,v0,u,v);
    advect(1,u,u0,u0,v0);
    advect(2,v,v0,u0,v0);
    project(u,v,u0,v0);
    enforce_obstacle_velocity(u,v);
}

// Sauvegarde densité (gnuplot : `set pm3d map; splot 'dens_xxx.dat' matrix`)
void save_density(double *dens, int step) {
    char fname[64];
    sprintf(fname,"dens_%04d.dat",step);
    FILE *fp = fopen(fname,"w");
    for (int j=1; j<=N; j++) {
        for (int i=1; i<=N; i++) {
            fprintf(fp,"%g ", dens[IX(i,j)]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    printf("Saved %s\n",fname);
}


// vecteurs (x y u v) échantillonnés
void save_velocity_quiver(const double *u, const double *v, int step, int stride) {
    char fn[64]; snprintf(fn,sizeof(fn),"vel_%04d.xyuv", step);
    FILE *fp = fopen(fn,"w"); if(!fp) return;
    for (int j=1; j<=N; j+=stride) {
        int row = j*(N+2);
        for (int i=1; i<=N; i+=stride) {
            // coords pixel (i,j) ; mets à l’échelle si tu veux [0,1]
            fprintf(fp, "%d %d %g %g\n", i, j, (double)u[row+i], (double)v[row+i]);
        }
        fputc('\n', fp); // séparateur de lignes (optionnel)
    }
    fclose(fp);
}

// Sauvegarde des champs en format VTK (ASCII legacy, 2D)
void save_vtk(int step, double *u, double *v, double *dens, unsigned char *solid) {
    char fname[64];
    sprintf(fname, "field_%04d.vtk", step);
    FILE *fp = fopen(fname, "w");
    if (!fp) return;

    int nx = N + 2;
    int ny = N + 2;
    double dx = 1.0 / N;

    // --- entête VTK ---
    fprintf(fp, "# vtk DataFile Version 3.0\n");
    fprintf(fp, "Navier-Stokes step %d\n", step);
    fprintf(fp, "ASCII\n");
    fprintf(fp, "DATASET STRUCTURED_POINTS\n");
    fprintf(fp, "DIMENSIONS %d %d 1\n", nx, ny);
    fprintf(fp, "ORIGIN 0 0 0\n");
    fprintf(fp, "SPACING %g %g 1.0\n", dx, dx);
    fprintf(fp, "POINT_DATA %d\n", nx * ny);

    // --- Densité ---
    fprintf(fp, "SCALARS density float 1\n");
    fprintf(fp, "LOOKUP_TABLE default\n");
    for (int j = 0; j < ny; j++) {
        for (int i = 0; i < nx; i++) {
            fprintf(fp, "%g ", dens[IX(i,j)]);
        }
        fprintf(fp, "\n");
    }

    // --- Masque solide ---
    fprintf(fp, "SCALARS solid int 1\n");
    fprintf(fp, "LOOKUP_TABLE default\n");
    for (int j = 0; j < ny; j++) {
        for (int i = 0; i < nx; i++) {
            fprintf(fp, "%d ", solid[IX(i,j)]);
        }
        fprintf(fp, "\n");
    }

    // --- Champ de vitesse ---
    fprintf(fp, "VECTORS velocity float\n");
    for (int j = 0; j < ny; j++) {
        for (int i = 0; i < nx; i++) {
            fprintf(fp, "%g %g 0\n", u[IX(i,j)], v[IX(i,j)]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("Saved %s\n", fname);
}


int main() {
    // Champs
    double *u    = alloc_field();
    double *v    = alloc_field();
    double *u0   = alloc_field();
    double *v0   = alloc_field();
    double *dens = alloc_field();
    double *dens0= alloc_field();
    solid = alloc_mask();

    // Cylindre solide au centre (rayon en cellules)
    int cx = (N+2)/2, cy = (N+2)/2;
    double radius = N*0.12;  // ~12% de la largeur
    //build_solid_circle(cx, cy, radius);
    build_solid_square(N/4, N/4, N/4+5, N/2); // un obstacle rectangulaire

    for (int step=0; step<10000; step++) {
        // Réinitialiser sources
        memset(u0,0,(N+2)*(N+2)*sizeof(double));
        memset(v0,0,(N+2)*(N+2)*sizeof(double));
        memset(dens0,0,(N+2)*(N+2)*sizeof(double));

        // Inlet simple : injecte densité et vitesse à gauche (rangée j=cy)
        /* int j_in = cy;
        for (int i=1; i<=2; i++) { // deux colonnes d'injection
            if (!solid[IX(i,j_in)]) {
                dens0[IX(i,j_in)] = 200.0;
                u0[IX(i,j_in)]    = 8.0;   // jet vers +x
            }
        } */

        int j_in = cy;
        for (int i=N/2-5; i<N/2+5; i++) { // deux colonnes d'injection
            if (!solid[IX(0,i)]) {
                // dens0[IX(0,i)] = 200.0;
                // u0[IX(0,i)]    = 26.0;   // jet vers +x
                dens0[IX(1,i)] = 200.0;
                u0[IX(1,i)]    = 30.0*step/5000.0;   // jet vers +x
                // dens0[IX(2,i)] = 200.0;
                // u0[IX(2,i)]    = 26.0;   // jet vers +x
            }
        }

        
        // Avancer
        vel_step(u,v,u0,v0);
        dens_step(dens,dens0,u,v);

        // Sauvegarde
        if (step%10==0) {
        //   save_density(dens, step);
        //   save_velocity_quiver(u, v, step, /*stride=*/4);   // flèches tous les 4 pixels
            save_vtk(step, u, v, dens, solid);
        }
    }

    free(u); free(v); free(u0); free(v0); free(dens); free(dens0); free(solid);
    return 0;
}
