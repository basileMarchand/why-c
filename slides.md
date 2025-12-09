class: middle, slide_title

<img class="main_logo" src="static/media/logo_c.png">

<div class="slide-decor"></div>

# UE12 </br> Apprentissage de la programmation

## Introduction au `C`

<br><br><br><br><br><br>

<div style="position: absolute; bottom: 2%; left: 50%; transform: translate(-50%, 0%) scale(0.8);">
<div class="profile-card">
  <div class="banner"></div>
  <img class="avatar" src="static/media/linkedin/profil.jpeg" alt="Photo de profil">
  <div class="content">
    <h3 class="name">Basile Marchand</h3>
    <p class="title">Ingénieur calcul scientifique et HPC</p>
    <div class="company">
      <img src="static/media/linkedin/simvia.jpeg" alt="Logo Simvia">
    </div>
    <a href="https://www.linkedin.com/in/basilemarchand/" target="_blank" class="btn-linkedin">
      <img src="https://cdn-icons-png.flaticon.com/512/174/174857.png" alt="LinkedIn logo" width="20px">
      Voir le profil
    </a>

  </div>
</div>

</div>

---

layout: true
<img class="slide_header_cnrs" src="static/media/logo_c.png">

<div class="slide_footer">
    <div class="wrap">
        <span>2025 - <i> Introduction au C ? ✨ </i>  </span>
    </div>
</div>

<div class="linkedin-footer">
<a href="https://www.linkedin.com/in/basilemarchand/" target="_blank" class="linkedin-badge">
  <img src="https://cdn-icons-png.flaticon.com/512/174/174857.png" alt="LinkedIn logo">
  <span>@basilemarchand</span>
</a>
</div>

<div class="slide-decor"></div>

---

# La genèse du `C`

.cols[
.fifty[

**Langage historique**

Le `C` est développé dans les années 1970 par deux scientifiques des laboratoires Bell :

- Dennis Ritchie
- Ken Thompson

L'ambition initiale est de créer un langage de programmation bas niveau pour réécrire le système d'exploitation UNIX, initialement écrit en assembleur.

Cela donna naissance en 1972 au langage `C`, qui devint rapidement populaire pour son efficacité et sa portabilité.
]
.fifty[

<figure>
<img src="static/media/kt_and_dr.jpg" alt="Ken Thompson et Dennis Ritchie" width="100%"/>
<figcaption> K. Thompson et D. Ritchie </figcaption>
</figure>

    ]

]

---

# Le C en 4 caractéristiques

<br><br><br><br>
.center[
**Bas niveau**

**impératif**

**typé statiquement**

**compilé**
]

---

# C un langage bas niveau

Le C est un langage dit **bas niveau** car il offre un niveau d'abstraction moindre, vis à vis du hardware, des des langages de plus haut niveau comme Python. Dit autrement il va falloir comprendre un peu ce qui se passe dans un ordinateur pour être efficace.
<br><br>
L'aspect bas niveau du C se manifeste par :

- La gestion manuelle de la mémoire (allocation, libération)
- L'utilisation de pointeurs pour manipuler directement les adresses mémoire
- Un contrôle précis sur les types de données et leur représentation en mémoire
- Possibilité de manipulers des registres vectoriels (SSE, AVX, ...)

---

# C un langage impératif

Dans le monde de la programmation, il existe ce qu'on appelle des **paradigmes de programmation**. En gros c'est le style de programmation : fonctionnel, orienté objet, impératif, ...

Certains langages sont multi-paradigmes, i.e. permettent de programmer dans plusieurs styles. C'est le cas par exemple du C++, Python, JavaScript, ...

En revanche le C est un langage **impératif**. Cela signifie que la programmation se fait en décrivant une série d'instructions qui modifient l'état du programme. C'est grosso-modo le paradigme de la plupart des langages que vous avez pu croiser.

---

# C un langage statiquement typé

LA première grosse différence avec ce que vous avez pu voir jusqu'à maintenant.

.cols[
.fifty[
<br>

```python
>>> ma_variable = "coucou"
>>> type(ma_variable)
<class 'str'>
>>> ma_variable = 42
>>> type(ma_variable)
<class 'int'>
```

]
.fifty[
En Python vous avez l'habitude de définir une variable, lui affecter une valeur d'un certain type et ensuite lui affecter une valeur d'un autre type. La notion de type en Python existe. Mais le typage est dynamique et vous n'avez pas à vous en préoccuper.
]
]

En `C` cela va être le grand bouleversement pour vous, les variables sont statiquement typées, i.e. :

- Vous devez spécifier vous même le type des variables que vous créées
- Le type d'une variable ne peut pas être modifié au cours de l'exécution du programme !!

---

# Typage statique illustration

En `C` pour définir une variable il faut nécessairement indiquer son type

```c
  int ma_variable = 42;
```

Une fois `ma_variable` défini comme étant un `int`, impossible de lui affecter autre chose qu'un `int`.

```c
  ma_variable = "coucou"; /// 🛑 erreur !!!
```

---

# C un langage compilé

**LA** compilation, le truc qui là va vous perturber le plus.

.center[Mais c'est quoi la compilation ?]

Cela signifie que le code source que vous écrivez doit être transformé en code machine par un programme appelé compilateur avant de pouvoir être exécuté.

Par opposition, des langages comme Python ou JavaScript sont interprétés, i.e. le code source est exécuté directement par un interpréteur sans étape de compilation préalable. Quand vous exécuter un script Python, c'est l'interpréteur `Python` qui lit et exécute le code ligne par ligne.

```bash
$ python mon_script.py
```

---

# C un langage compilé

## Le compilateur

Pour réaliser cette opération de compilation on doit donc utiliser un programme externe appelé le compilateur. Ce programme va lire le code source que vous avez écrit et le transformer en code machine.

Les compilateurs C les plus couramment utilisés sont :

- GCC (GNU Compiler Collection)
- Clang (LLVM)
- MSVC (Microsoft Visual C++)

.def[Dans les faits, c'est un peu plus compliqué que ça. Le compilateur effectue plusieurs étapes intermédiaires avant d'arriver au code machine final. Et il est appuyé par d'autres outils comme l'éditeur de liens (linker) qui assemble les différents morceaux de code compilé en un exécutable final. Puis il y a aussi le préprocesseur qui traite les directives spéciales dans le code source avant la compilation proprement dite.
]

---

# C un langage compilé

## On fait comment ?

C'est très simple. Considérons l'exemple classique du Hello World. Le code C pour afficher le message Hello World est le suivant :

.cols[
.fifty[

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("Hello, World!\n");
  return EXIT_SUCCESS;
}
```

]
.fifty[
Pour compiler ce code source en un exécutable, on utilise la commande suivante

```bash
$ gcc hello.c -o hello
```

]
]
où `gcc` est le compilateur, `hello.c` est le fichier source, et `-o hello` spécifie le nom de l'exécutable généré.

.cols[
.fifty[
**Attention** le code a été compilé mais pas exécuté. C'est à vous ensuite de lancer l'exécutable généré.
]
.fifty[

```bash
$ ./hello
```

]
]

---

# C un langage compilé

## Pleins d'info en vrac

- Le code source C est généralement stocké dans des fichiers avec l'extension `.c` pour les fichiers source et `.h` pour les fichiers d'en-tête (headers).
- Le processus de compilation peut être divisé en plusieurs étapes : prétraitement, compilation, assemblage et édition des liens.
- Les options de compilation peuvent être utilisées pour contrôler divers aspects du processus de compilation, comme le niveau d'optimisation, les avertissements, etc.
- **Par défaut le code compilé n'est pas compatible avec un autre OS ou une autre architecture matérielle.** Il faut recompiler le code source sur la plateforme cible pour obtenir un exécutable compatible.

---

# C un langage compilé

## Un mot sur les options de compilation

Une grande devise dans le monde du C est :
.center[**"Trust the compiler, not the programmer."**]

Et une autre devise que j'aime bien :
.center[**"Le warning d'aujourd'hui est l'erreur de demain."**]

Personnellement je vous conseillerais de compiler vos codes avec les options suivantes :

```bash
$ gcc -Wall -Wextra -Wpedantic -fanalyzer mon_code.c -o mon_executable
```

Alors oui cela donne des choses assez verbeuses et détecte beaucoup de choses, mais au moins si vos code compilent avec ces options sans aucuns warning vous partez avec des bases saines.

---

# C un langage compilé

## Démo des options

Considérons le code suivant :

.cols[
.fifty[

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
  int a = 42;
  double x;
  x += (double)a;
  return EXIT_SUCCESS;
}
```

Sans aucune option de compilation ce code compile parfaitement sans aucune warning.
]
.fifty[

.smaller[

```bash
$ gcc -Wall -Wextra -Wpedantic -fanalyzer test.c
test.c: In function ‘main’:
test.c:8:5: warning: ‘x’ is used uninitialized [-Wuninitialized]
    8 |   x += (double)a;
      |   ~~^~~~~~~~~~~~
test.c:7:10: note: ‘x’ was declared here
    7 |   double x;
      |          ^
test.c:8:5: warning: use of uninitialized value ‘x’ [CWE-457] [-Wanalyzer-use-of-uninitialized-value]
    8 |   x += (double)a;
      |   ~~^~~~~~~~~~~~
  ‘main’: events 1-2
    |
    |    7 |   double x;
    |      |          ^
    |      |          |
    |      |          (1) region created on stack here
    |    8 |   x += (double)a;
    |      |   ~~~~~~~~~~~~~~
    |      |     |
    |      |     (2) use of uninitialized value ‘x’ here
```

]
]
]

---

# Structure générale d'un programme C

## Le point d'entrée

Dans un programme Python, le point d'entrée, i.e. là où commence l'exécution de votre programme c'est la première ligne du fichier Python que vous exécutez.

.center[En `C` la logique est un peu différente]

Le point d'entrée d'un programme `C` (c'est d'ailleur la même chose pour en `C++`) c'est une fonction. Cette fonction s'appelle nécessairement `main`.
.cols[
.fifty[

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
  ....
  return EXIT_SUCCESS;
}
```

]
.fifty[
Cette fonction retourne un entier, cet entier peut-être récupéré dans le terminal à l'issue de l'exécution du programme en utilisant `$?`
]
]

---

# Structure générale d'un programme C

## Les includes

Dans un programme C on trouver généralement en haut du fichier `.c` des instructions de la forme
`#include <truc.h>`.

Il s'agit d'une directive de pré-compilation. Elle signigie litéralement qu'il faut inclure dans le fichier courant, le contenu du fichier `truc.h` avant de passer à l'étape de compilation à proprement parlé.

Le fichier `truc.h` est ce qu'on appelle un fichier d'en-tête, _header_ file. C'est fichier permettent de déclarer au compilateur que des fonctions que l'on a pas codé soit-même existent.

Par exemple quand on utilise `printf` pour afficher un message on doit faire un `#include  <stdio.h>` sinon le compilateur nous dit qu'il ne connait pas `printf`.

---

# Les variables

## Le principe d'une variable

Une variable c'est quoi ? C'est tout simplement une étiquette, un nom, que l'on associe à une zone mémoire dnas laquelle sera stockée la valeur associée à la variable.

La notion de type apparaît alors pour permettre deux choses :

1. Déterminer la taille nécessaire en mémoire pour stocker la valeur d'une variable
2. Savoir comment interpréter une série de `0` et de `1`, car pour une méme zone mémoire, l'interprétation ne sera pas la même suivant si on considère un entier ou bien un flottant.

---

# Les variables

## Déclaration vs affectation

La déclaration d'une variable se fait en suivant le pattern suivant :

```c
type nom_variable;
```

En `C` il n'y a pas une convention de nommage de variables, contrairement à Python et la PEP8. A vous de choisir ce que vous voulez, essayez juste d'être cohérent d'un bout à l'autre du code. Les noms de variables doivent répondre à quelques rêgles élémentaires :

- Commencer par une lettre
- Pas d'espace
- Pas de caractères spéciaux

---

# Les Types

## Les nombres

Le `C` met à disposition un certain nombre de type de _base_. C'est type sont des types numériques il s'agit de

🧮 Les types numériques se divisent en deux grandes catégories :

| Famille       | Exemples                         | Nature                                       |
| ------------- | -------------------------------- | -------------------------------------------- |
| **Entiers**   | `int`, `short`, `long`, `char`   | Valeurs **exactes**, sans partie décimale    |
| **Flottants** | `float`, `double`, `long double` | Valeurs **approchées**, avec partie décimale |

💡 En C, chaque type correspond à une taille en mémoire (nombre de bits), et donc à une plage de valeurs possible.

---

# Les types

## Quelques mots sur les entiers

| Type        | Taille typique | Exemple de valeur                  | Commentaire                         |
| ----------- | -------------- | ---------------------------------- | ----------------------------------- |
| `char`      | 1 octet        | `'A'`, `97`                        | Souvent utilisé pour les caractères |
| `short`     | 2 octets       | `-32768` à `32767`                 | Petit entier                        |
| `int`       | 4 octets       | `-2,147,483,648` à `2,147,483,647` | Type entier standard                |
| `long`      | 4 ou 8 octets  | selon système                      | Entier long                         |
| `long long` | ≥ 8 octets     | jusqu’à 9 223 372 036 854 775 807  | Très grand entier                   |

⚠️ La taille dépend du compilateur et de l’architecture (32 ou 64 bits). Il existe un moyen de garantir la taille des entiers `#include <stdint.h>`

---

# Les types

## Entiers de taille fixe

```c
#include <stdint.h>
```

| Type       | Taille garantie | Signé | Exemple de valeur               |
| ---------- | --------------- | ----- | ------------------------------- |
| `int8_t`   | 8 bits          | oui   | −128 → +127                     |
| `uint8_t`  | 8 bits          | non   | 0 → 255                         |
| `int16_t`  | 16 bits         | oui   | −32768 → +32767                 |
| `int32_t`  | 32 bits         | oui   | −2 147 483 648 → +2 147 483 647 |
| `uint32_t` | 32 bits         | non   | 0 → 4 294 967 295               |
| `int64_t`  | 64 bits         | oui   | valeurs très grandes            |
| `uint64_t` | 64 bits         | non   | valeurs très grandes            |

---

# Les types

## Quelques mots sur les flottants

| Type          | Taille typique | Précision                        | Exemple                |
| ------------- | -------------- | -------------------------------- | ---------------------- |
| `float`       | 4 octets       | ~7 chiffres                      | `3.141593f`            |
| `double`      | 8 octets       | ~15 chiffres                     | `3.141592653589793`    |
| `long double` | 16 octets      | ~18 chiffres (selon compilateur) | `3.141592653589793238` |

Les flottants sont codés selon la norme IEEE 754 :

| Élément      | Rôle                   |
| ------------ | ---------------------- |
| **Signe**    | positif/négatif        |
| **Exposant** | ordre de grandeur      |
| **Mantisse** | chiffres significatifs |

**Exemple :** `float x = 12.5;`
→ stocké en binaire comme (-1)^s × 1.mantisse × 2^(exposant-127)

---

# Les types

## Utilisation des suffix

Quand tu écris une valeur numérique dans ton code C, le compilateur lui attribue un type par défaut : `int` pour les entiers, `double` pour les réels.

.cols[
.sixty[

| Suffixe    | Type résultant       | Exemple |
| ---------- | -------------------- | ------- |
| _(aucun)_  | `int`                | `42`    |
| `U` ou `u` | `unsigned int`       | `42U`   |
| `L` ou `l` | `long int`           | `42L`   |
| `UL`, `LU` | `unsigned long int`  | `42UL`  |
| `LL`       | `long long int`      | `42LL`  |
| `ULL`      | `unsigned long long` | `42ULL` |

]
.fourty[
| Suffixe | Type | Exemple |
| ---------- | ------------- | ------- |
| _(aucun)_ | `double` | `3.14` |
| `f` ou `F` | `float` | `3.14f` |
| `l` ou `L` | `long double` | `3.14L` |

]
]

⚠️ À retenir

- ✅ Toujours suffixer les valeurs quand tu veux contrôler le type exact.
- ✅ Indispensable pour les grandes constantes ou les calculs précis.
- ✅ Bon réflexe pour éviter les warnings de conversion implicite.

---

# Les types

## Pas de mélange des genres

Le `C` de par sa nature fortement typé, n'est pas très adepte du mélange des genres. Par exemple lorsque vous faites :

.cols[
.fifty[

```c
int a = 42;
float b = 0.1;
double c = 43.0;

double out = a*b + c;
```

]
.fifty[
Le résultat est défini comme étant un double et c'est logique. Mais en interne du `C` que se passe-t-il à votre avis ?
]
]

--

Et bien le `C` va automatiquement changer les types des variables `a`, `b` et du résultat de `a*b`

.cols[
.fifty[

```c
double out = (double)((float)a*b) + c;
```

]
.fifty[
La conversion automatique se fait uniquement dans le sens où il est garanti qu'il n'y aura **pas de perte** d'information.
]
]

---

# Les types

## Opération de cast

Cette opération de conversion d'une valeur d'une variable d'un type vers un autre est ce qu'on appelle un **_cast_**.
Le **_cast_** peut être :

- Implicite : c'est le compilateur qui choisi de le faire, c'est par exemple ce qui est arrivé dans l'exemple de la slide précédente
- Explicite : c'est le développeur qui va spécifier, via une syntaxe partciulière, que la valeur d'une variable doit être interpréter d'une manière différente.

Cette syntaxe particulière est la suivante :
.cols[
.fifty[

```c
(target_type)source_variable;
```

]
.fifty[

```c
int a=42;
double x=(double)a;
```

]
]

.cols[
.fourty[
Une astuce que j'aime bien
]
.sixty[

```c
#define static_cast(type, value) ((type)(value))

double x=static_cast(double, a);

```

]

]

---

# Les types

## Un mot sur les char

En C, le type char sert à représenter un caractère unique, mais c’est avant tout… un entier sur 1 octet (8 bits) !

Pourquoi un entier sur 8 bits = un charactère. C'est lié à la table ASCII _(American Standard Code for Information Interchange)_

.cols[
.fifty[
| Caractère | Code ASCII décimal | Code binaire |
| -------------- | ------------------ | ------------ |
| `'A'` | 65 | `01000001` |
| `'B'` | 66 | `01000010` |
| `'a'` | 97 | `01100001` |
| `'0'` | 48 | `00110000` |
| `' '` (espace) | 32 | `00100000` |

]
.fifty[
| Type | Taille | Commentaire |
| --------------- | ------- | ----------------------------------------------------------------------------- |
| `char` | 1 octet | signé ou non selon le compilateur |
| `signed char` | 1 octet | valeurs négatives possibles |
| `unsigned char` | 1 octet | toujours positif, utile pour stocker des octets bruts (ex: fichiers binaires) |

]
]

--

.cols[
.fifty[
Un char reste un nombre, on peut donc faire des opérations :
]
.fifty[

```c
printf("%c\n", 'A' + 1); // affiche 'B'
```

]
]

---

# Les types

## Les booléens

En `C` depuis la norme C23 le type `bool` est devenu un type natif du langage ainsi que les constante `true` et `false`.

On peut inclure l'en-tête `<stdbool.h>` pour utiliser ce type dans les versions antérieures de la norme C. On dispose avec les booléens, de toutes les opérations logiques classiques : `&&` (et), `||` (ou), `!` (non). Le Xor logique n'est pas natif mais on peut l'implémenter facilement.

Les booléens nous servirons surtout dans les opérations de branchements, ou bien comme conditions d'arrêt dans les boucles.

---

# Les types et variables

## Notion de scope

La portée d'une variable, son scope, correspond à la portion du code qui a la possibilité d'accéder à cette variable en lecture(/écriture). En `C` le scope d'une variable est restreint au bloc d'instruction dans lequel cette variable est définie. Bloc d'instruction = portion de code contenu entre deux accolades `{` `}`.

```c
// Scope principal A
int a;
{ // DEBUT du Scope secondaire A.1
  a = 42; // Ok car appartenant à A
  int b = a+1;
  { // DEBUT du Sous-sous-scope A.1.1
    printf("La valeur de b est %d", b); // Ok
  } // FIN du sous-sous-scope A.1.1
} // FIN du sous-scope A.1
{
  printf("La valeur de a est %d", a); // Ok est affiche 42
  printf("La valeur de b est %d", b); // NOT OK car b a été détruit
                                      // à la FIN de A.1
}
```

---

# Les types

## Qualificateur `const`

A une variables est associée un type, auquel on peu ajouter un qualificateur via le mot clé `const`.

Tout simplement, cela permet de spécifier au compilateur que la valeur de la variable en question ne changera **jamais**. Par exemple

```c
const size_t nb_eleve_dans_mon_groupe = 17;
```

---

# Les types

## `sizeof`

Une fonction que l'on va être amené à beaucoup manipuler par la suite de votre avanture dans le monde du `C` est `sizeof`. `sizeof` permet de récuper la taille mémoire **en octet**, d'une variable **ou** d'un type.
.cols[
.sixty[

```c
int a = 42;
float b = 0.1;
double c = 43.0;
size_t sz_a = sizeof(a);
printf("Size of a: %zu\n", sz_a);
printf("Size of int: %zu\n", sizeof(int));
size_t sz_b = sizeof(b);
printf("Size of b: %zu\n", sz_b);
printf("Size of float: %zu\n", sizeof(float));
size_t sz_c = sizeof(c);
printf("Size of c: %zu\n", sz_c);
printf("Size of double: %zu\n", sizeof(double));
```

]
.thirty[

```shell
$ ./a.out
Size of a: 4
Size of int: 4
Size of b: 4
Size of float: 4
Size of c: 8
Size of double: 8
```

]
]

---

# Les types et variables

## Je suis rangé où `&`

Pour finir sur notre tour d'horizon rapide des types et variables on va voir une petite chose, qui pour le moment va vous sembler au mieux étrange, au pire inutile, c'est la possibilité de récupérer l'adresse mémoire d'une variable.

```c
int a = 42;
printf(f"L'adresse en mémoire de a est %p", (void *)&a);
```

```bash
$ ./a.out
L'adresse en mémoire de a est 0x7fff63dcce74
```

---

class: middle,

# Types et variables en trois rêgles

1. Une variable doit être déclarée avant d'être utilisée, au plus proche de son premier usage.
2. La conversion de type, doit toujours être faite explicitement pour assurer la portabilité entre plateforme
3. Tout ce qui est constant doit être `const`

---

# Les contrôles du flux d'exécution

Dans tout programme informatique, il arrive régulièrement que suivant l'état courant du programme on veuille faire une chose plutôt qu'une autre. On parle de branchement. En `C` on retrouve, ce que vous avez déjà vu par ailleurs à plusieurs structures de contrôles qui permettent d'aiguiller l'exécution de votre programme.

Les structures de contrôles en `C` sont les suivantes :

- `if` ... `else if` ... `else` : le classique que vous connaissez déjà
- `swicth` ... `case` : du old school qui a son intérêt, mais pas indispensable
- `goto` : un truc de vieux, donc forcément bien

---

# Les contrôles du flux d'exécution

## `if`, `else if`, `else`

La structure de contrôle `if` est celle que vous connaissez à coup sur. Le comportement est le même en `C` que celui que vous avez déjà vu en Python. La seule différence est dans la syntaxe

```c
int age= ... ;
if( age < 18){
  printf("");
}
else if(age >= 18 && age <=35){
  printf("Encore jeune");
}
else{
  printf("Commence certainement à être usé");
}
```

---

# Les contrôles du flux d'exécution

## `switch`

Alternative au `if` qui repose sur la comparaison d'une valeur avec différents cas possibles. On est donc sur des égalités strictes, contrairement au `if` où l'on peut utiliser n'importe quelle expression booléenne.

.cols[
.seventy[

```c
switch (variable){
  case 7:
    printf("Le nombre d'Horcruxe");
    break;
  case 9:
    printf("Le nombre de biju");
    break;
  case 42:
    printf("42 est la réponse à la question universelle");
    break;
  default:
    printf("Star Wars c'était mieux avant Disney");
}

```

]
.thirty[
**Attention** le mot-clé `break` indique qu'une fois rentré dans un `case` le code doit sortir du `switch`. Sans le `break` tous les cases suivants seraient exécutés.
]
]

---

# Les contrôles du flux d'exécution

## `Switch` sans le `break`

Par exemple :
.sixty[

```c
printf("A l'age de %d tu es \n")
switch (age){
  case 35:
    printf("Plein de sagesse\n");
  case 30:
    printf("au top de ta carrière\n");
  case 25:
    printf("Dans une forme olympique\n");
  case 20:
    printf("Débordant d'énergie");
}
```

]
.cols[
.sixty[
Et oui, sans le `break` dès qu'on rentre dans un `case` on passe par tous les suivants. Cela peut avoir un intérêt mais il faut bien le maîtriser et savoir ce que l'on fait.
]
.fourty[

```bash
$ ./a.out
A l'age de 35 tu es
Plein de sagesse
au top de ta carrière
Dans une forme olympique
Débordant d'énergie
```

]
]

---

# Les contrôles du flux d'exécution

## `goto`

Le `goto` est une commande qui permet de sauter directement à une étiquette ailleurs dans le même bloc d'instruction.

.cols[
.fifty[

```c
int x=42;
x += 1;
if(x == 43){
goto etiquette;
}
printf(" x = %d\n", x);
etiquette:
printf("Atteint l'étiquette\n");
```

```bash
$ ./a.out
Atteint l'étiquette
```

]
.fifty[
La ligne qui affiche la valeur de `x` n'est pas exécuté car on passe par le `goto` avant et donc on saute directement aux denières lignes.

**Attention** le `goto` n'est généralement pas recommandé, car mène à des codes compliqués à lire et maintenir. Il ne doit être utilisé que si vraiment il permet un gain de clarete/simplicité du code.  
]
]

---

# Les boucles

Une des forces de l'ordinateur, par rapport à l'humain, c'est qu'il accepte de répéter les mêmes opérations autant de fois que nécessaire (i.e. qu'on lui demande). Car généralement, un programme informatique est fait pour traiter un gros paquet de données. Et rien de mieux pour cela que faire des boucles. Le `C` comme beaucoup d'autre langage a à sa disposition deux solutions pour faire des boucles.

- La boucle `for` qui permet de répéter `N` fois un bloc d'instruction, avec `N` connu à l'avance
- La boucle `while` qui permet de répéter tant qu'une condition n'est pas satisfaite, un bloc d'instuction.

---

# Les boucles

## `while` et `do` ... `while`

La boucle `while` en `C` ressemble énormément à ce que vous connaissez en Python.

.cols[
.fifty[

```c
int i=0;
while(i<10){
  i+=1;
  printf("i=%d\n", i);
}
```

]

]

.cols[
.fifty[
La version `do{...} while ()` évalue la condition en fin de chaque itération, ce qui permet de rentrer dans le while au moins une fois même si à l'état initiale la conditions d'arrêt est déjà satisfaite.
]
.fifty[

```c
int i=-2;
do {
  i+=1;
  printf("i=%d", i);
} while( i>0);
```

]
]

---

# Les boucles

## `for`

La boucle `for` pour le coup diffère un petit peu de ce que vous connaissez en Python. En Python, la boucle `for` parcourt des **itérables** alors qu'en `C` la boucle `for` est destinée au boucles comptées, i.e. boucle sur un index que l'on incrémente/décrémente. La syntaxe typique est

```c
for( initialisation ; test ; incrémentation ){
  // Corps de la boucle
}
```

.cols[
.fifty[
Par exemple pour afficher les entiers de 0 à 9 on peut procéder de la manière suivante :
]
.fifty[

```c
for(size_t i=0; i<10; i++){
  printf("i = %zu", i);
}
```

]
]

---

# Les boucles

## `for` - deux, trois petites choses

.cols[
.fifty[
La variable compteur d'une boucle `for` peut-être définie en dehors de la boucle.
]
.fifty[

```c
size_t i;
for(i=0; i<10; i++){
  ...
}
```

]
]

.cols[
.fifty[

```c
size_t i=0;
for(; i<10; i++){
  ...
}
```

]
.fifty[
On peut même se passer d'un ou plusieurs éléments entre parenthèses du `for`
]
]

---

# Les boucles

## `break` and `continue`

Comme en Python, il existe les deux mots clés `break` et `continue` qui permettent de modifier l'exécution d'une boucle `for` ou `while`.

.cols[
.fourty[
`break` — sortir de la boucle

```c
for (int i = 0; i < 10; i++) {
    if (i == 5)
        break;
    printf("%d ", i);
}
```

```bash
$ ./a.out
0 1 2 3 4
```

]
.sixty[
`continue` — passer à l’itération suivante

```c
for (int i = 0; i < 10; i++) {
    if (i == 5)
        continue;
    printf("%d ", i);
}
```

```bash
$ ./a.out
0 1 2 3 4 6 7 8 9
```

]
]

---

class: middle

# Branchements et boucles

1.
2.
3.

---

# Les fonctions

évidemment en `C` comme dans beaucoup d'autre langage on peut définir des fonctions, i.e. des blocs d'instructions réutilisables sans faire de copy/paste

💡 Le but des fonctions est multiple :

- éviter de répéter du code,

- rendre le programme plus lisible,

- mieux structurer le raisonnement.

---

# Les fonctions

## Définition

Une fonction en C suit cette forme générale pour sa définition :

```c
type_retour nom_fonction(type1 arg1, type2 arg2, ... ){
  // bloc
  // d'instruction
  return valeur;
}
```

Avec la contrainte que `valeur` forcément une varible de type `type_retour`.

.cols[
.fourty[
Par exemple, pour définir une fonction qui ferait la somme de deux entiers
]
.sixty[

```c
int addition(int a, int b) {
  int c = a + b;
  return c;
}
```

]
]

---

# Les fonctions

## Utilisation

Pour utiliser une fonction, on l’appelle depuis main() ou une autre fonction.

.cols[
.fifty[

```c
#include <stdio.h>

int addition(int a, int b) {
    return a + b;
}

int main() {
    int x = 3, y = 5;
    int s = addition(x, y);
    printf("Somme = %d\n", s);
    return 0;
}
```

]
.fifty[

```bash
$ ./a.out
Somme = 8
```

**Attention** pour pouvoir utiliser `addition` il faut que le compilateur sache avant l'appel que la fonction existe.

]
]

.cols[
.fifty[
📦 Fonction ≠ Procédure
Si elle ne renvoie rien → type void
]
.fifty[

```c
void affiche_message() {
    printf("Bonjour !\n");
}
```

]
]

---

# Les fonctions

## Notion de prototype

Avant d’utiliser une fonction, le compilateur doit connaître sa signature, i.e. le type de sortie ainsi que le nombre d'arguments et les types associés.

.cols[
.fifty[
On peut définir le prototype d'une fonction avant de spécifier son implémentation. C'est ce que l'on décompose comme étant la **déclaration** d'une fonction vs la **définition**.

C'est ce mécanisme qui va nous permettre par la suite de **décomposer** nos programmes en **plusieurs fichiers**.
]
.fifty[

```c
// Prototype (déclaration)
*int addition(int a, int b);

int main() {
    int r = addition(3, 4);
    printf("%d\n", r);
    return 0;
}

// Définition
int addition(int a, int b) {
    return a + b;
}
```

]
]

---

# Pour finir

## Un mot sur les IO

Le `C` dispose nativement de deux fonctions permettant de faire des entrées/sorties et donc d'avoir une interaction avec l'utilisateur. Pour la sortie vous l'avez déjà vu c'est `printf` et son alter ego est `scanf`.

```c
#include <stdio.h>
```

Ces deux fonctions reposent sur la notion de formatage. Les caractères de formatage sont les suivants (liste non exhaustive)

| Format | Type affiché             | Exemple                  |
| ------ | ------------------------ | ------------------------ |
| `%d`   | entier (`int`)           | `printf("%d", 42);`      |
| `%f`   | réel (`float`, `double`) | `printf("%f", 3.14);`    |
| `%c`   | caractère (`char`)       | `printf("%c", 'A');`     |
| `%s`   | chaîne de caractères     | `printf("%s", "Hello");` |

---

# Pour finir

## Un mot de plus sur `scanf`

.cols[
.fifty[
`scanf` permet de lire une valeur tapée par l’utilisateur dans le terminal.

⚠️ Le symbole `&` est obligatoire, il indique l’adresse mémoire où stocker la valeur saisie.
]
.fifty[

```c
scanf("formats", &variables);
```

]
]

Par exemple à l'usage cela donne :

```c
#include <stdio.h>

int main() {
    int age;
    printf("Quel âge as-tu ? ");
    scanf("%d", &age);
    printf("Tu as %d ans.\n", age);
    return 0;
}
```

---

class: middle, center

# Des questions ?

---

# Mise en oeuvre

## Facile

.cols[
.fifty[
**Convertisseur Celsius ↔ Fahrenheit**

Entrer une température en Celsius et afficher l’équivalent en Fahrenheit.

$$𝐹=𝐶×95+32$$
💡 Variante : proposer un menu texte pour choisir le sens de la conversion.
]
.fifty[

    **Évaluer une expression simple**

Lire deux entiers et afficher la somme, la différence, le produit et le quotient.

💡 Variante : forcer le type float pour la division.
💡 Variante : permettre à l'utilisateur de choisir s'il veut des opérations entières ou flottantes.
]
]

---

# Mise en oeuvre

## Facile 2

.cols[.fifty[

**Table de multiplication**

Afficher la table de multiplication d’un nombre donné.

💡 Variante : afficher toutes les tables de 1 à 10 avec deux boucles imbriquées.

**Somme des n premiers entiers**

Lire n et calculer la somme des entiers de 1 à n.

💡 Variante : comparer la somme obtenue à la formule
**𝑛(𝑛+1)/2**
]
.fifty[
**Nombre mystère**

Générer un nombre entre 1 et 100 (fixe pour le moment, ex. 42) et demander à l’utilisateur de deviner, avec des indications “trop grand / trop petit”.

💡 Variante : ajouter un compteur d’essais.
]]

---

# Mise en oeuvre

## Un tout petit peu moins simple

**Convertisseur binaire**

Entrer un entier positif et afficher sa représentation binaire (sans tableau : imprimer les bits à l’envers, ou utiliser une boucle while(n > 0) avec division par 2).

**Triangle de caractères**
.cols[
.sixty[
Lire un entier n et afficher un triangle de `x`

💡 Variante : triangle isocèle

]
.fourty[

```
x
xx
xxx
xxxx
```

]
]

**Approximation de π**

Implémenter une fonction `float approx_pi(int n)` qui calcule

$$π≈4×(1−1/3+1/5−1/7+…)$$

---

class: center, middle

# Séance 2

## Types dérivés, coding style et clean code

---

# Les types dérivés

En `C` on dispose des types de base qu'on a déjà vu précédemment, mais aussi de types dit "dérivés".

Ces types dérivés sont :

- Les tableaux
- Les chaînes de caractères
- Les structures
- Les pointeurs

Ces types dérivés, vous allez le voir rapidement, ne sont que des **variantes/combinaisons** des types de base. Ils sont néanmoins très importants car ils permettent de manipuler des données plus complexes.

---

# Les pointeurs

## Notion d'adresse mémoire

En `C`, chaque variable est stockée à une adresse mémoire spécifique. Un pointeur est une variable qui **contient l'adresse mémoire** d'une autre variable. Un pointeur est défini en utilisant le symbole `*` lors de la déclaration.

```c
type *nom_pointeur;
```

où `type` est le type de la variable pointée.

```c
int a = 42;          // Variable entière
int *p = &a;        // Pointeur vers un entier, initialisé à l'adresse de a
printf("Valeur de a: %d\n", *p); // Affiche 42
```

⚠️ Le symbole `&` est l'opérateur "adresse de", qui récupère l'adresse mémoire d'une variable.
Le symbole `*` est l'opérateur de "déréférencement", qui accède à la valeur stockée à l'adresse pointée par le pointeur

---

# Les pointeurs

## Initialisation et utilisation

Un pointeur doit être initialisé avant d'être utilisé. Il peut être initialisé à l'adresse d'une variable existante ou à `NULL` (indiquant qu'il ne pointe vers rien). Depuis C23, on peut utiliser le mot-clé `nullptr` pour représenter un pointeur nul.

.cols[
.fifty[

```c
int a = 10;
int *p = &a;
printf("Valeur de a via p: %d\n", *p);
```

]
.fifty[

```c
int *p = nullptr; // ou int *p = NULL;
if (p != nullptr) {
    // Utilisation de p
} else {
    printf("Pointeur nul\n");
}
```

]
]

**Rêgles** : toujours vérifier qu'un pointeur n'est pas nul avant de le déréférencer.

---

# Les pointeurs

## Mais à quoi ça sert ?

Les pointeurs sont utilisés pour :

- Manipuler des tableaux et des chaînes de caractères.
- Passer des arguments par référence aux fonctions (permet de modifier la variable d'origine).
- Créer des structures de données complexes (listes chaînées, arbres, etc.).
- Gérer la mémoire dynamique (allocation et libération de mémoire).

Aujourd'hui, on va se concentrer sur les deux premiers points. Les deux derniers ce sera pour la séance suivante quand on abordera le sujet passionant de la gestion mémoire !

---

# Les pointeurs

## Arguments de fonction par référence

.cols[
.fourty[
En `C`, les arguments des fonctions sont **passés par valeur**, donc une copie de la variable est faite. En utilisant des pointeurs, on peut simuler le passage par référence.

]
.sixty[

```c
void increment(int *p) {
    (*p)++; // Incrémente la valeur pointée par p
}

int main() {
    int a = 5;
    increment(&a); // Passe l'adresse de a
    printf("a après incrémentation: %d\n", a); // Affiche 6
    return 0;
}
```

]
]

.cols[.fifty[
En **`C` moderne**, pour spécifier que la fonction `increment` attend un **pointeur non nul**, on peut utiliser `int p[static 1]` dans la déclaration de la fonction.
]
.fifty[

```c
void increment(int p[static 1]) {
    (*p)++; // Incrémente la valeur pointée par p
}
```

]
]

---

# Les pointeurs

## Quelques infos en vrac ?

Et ça fait quelle taille en mémoire un pointeur ?

```c
int *p;
printf("Taille d'un pointeur: %zu octets\n", sizeof(p));
```

```bash
$ ./a.out
Taille d'un pointeur: 8 octets
```

La taille d'un pointeur dépend de l'architecture de la machine (32 bits vs 64 bits). Sur une architecture 64 bits, un pointeur occupe généralement 8 octets. La taille d'un pointeur est **indépendante** du type de données qu'il pointe.

---

# Les pointeurs

## Durée de vie et portée

.cols[
.fifty[
La durée de vie d'un pointeur dépend de la portée de la variable qu'il pointe. Si le pointeur pointe vers une variable locale, il devient invalide lorsque cette variable sort de son scope.

]
.fifty[

```c
int *create_pointer() {
    int a = 42;
    return &a; // Dangling pointer !
}
```

]
]

⚠️ Ne jamais retourner l'adresse d'une variable locale depuis une fonction, cela crée un **dangling pointer** (pointeur pendu) qui pointe vers une zone mémoire invalide.

.cols[
.fourty[
A contrario, lorsqu'un pointeur est détruit, la mémoire qu'il pointait ne l'est pas.

]
.sixty[

```c
int a = 42;
{
int *p = &a;
// p est détruit ici, mais a reste valide
}
printf("%d\n", a); // Toujours valide
```

]
]

---

# Les tableaux

## En une slide

En `C` un tableau est une collection de variables du **même type**, stockées de manière **contiguë** en mémoire. Chaque élément du tableau est accessible via un index.
La déclaration d'un tableau se fait de la manière suivante :

```c
type nom_tableau[taille];
```

où `type` est le type des éléments du tableau, `nom_tableau` est le nom que vous donnez au tableau, et `taille` est le nombre d'éléments que le tableau peut contenir. Cette taille doit être une constante entière positive et connue à la compilation.

.cols[
.fifty[

```c
int tab[5]; // Déclaration d'un tableau de 5 entiers
tab[0] = 10; // Affectation de la première case
tab[1] = 20; // Affectation de la deuxième case
printf("%d\n", tab[0]); // Affiche 10
```

]
.fifty[
⚠️ En C, les indices des tableaux commencent à 0. Donc pour un tableau de taille `n`, les indices vont de `0` à `n-1`.
]
]

---

# Les tableaux

## Initialisation

Un tableau peut être initialisé lors de sa déclaration en utilisant des accolades `{}` pour spécifier les valeurs initiales.
.cols[
.fifty[

```c
int tab[5] = {10, 20, 30, 40, 50}; // Initialisation complète
```

]
.fifty[

```c
int tab[5] = {10, 20}; // Initialisation partielle, les
// autres éléments sont mis à 0
```

]
]

En `C`, si vous ne fournissez pas de taille explicite lors de l'initialisation, le compilateur déduit la taille du tableau à partir du nombre d'éléments fournis.

```c
int tab[] = {10, 20, 30}; // Taille déduite à 3
```

Vous pouvez également spécifier la position d'initialisation des éléments :

```c
int tab[5] = {[2] = 30, [4] = 50}; // tab[0] et tab[1] sont 0, tab[2] est 30, tab[3] est 0, tab[4] est 50
```

---

# Les tableaux

## Attention aux pièges

**Attention**, en `C`, contrairement à ce que vous connaissez par ailleurs :

- La taille d'un tableau doit être une constante connue à la compilation.
- Si vous passez votre tableau à une fonction, vous perdez l'information de sa taille.
- Il n'y a pas de vérification des limites d'accès aux tableaux. Accéder à un index hors des bornes définies conduit à un comportement indéfini.

Quand on écrit `int tab[5];`, le compilateur réserve un bloc de mémoire contiguë pour 5 entiers. Chaque entier occupe généralement 4 octets (cela dépend de l'architecture), donc le tableau occupe 20 octets au total.

.def[
En réalité, le nom du tableau `tab` est traité comme un pointeur vers le premier élément du tableau. Donc `tab` équivaut à `&tab[0]`. Mais on verra cela plus tard.
]

---

# Les tableaux

## Argument de fonction, pointeur et tableau

En `C`, lorsque vous passez un tableau à une fonction, ce que vous passez réellement est un pointeur vers le premier élément du tableau. Par conséquent, la taille du tableau n'est pas transmise automatiquement à la fonction. Il est donc courant de passer la taille du tableau en argument supplémentaire.

```c
void afficher_tableau(int tab[], size_t taille) {
    for (size_t i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}
```

Ce passage par pointeur permet à la fonction de modifier les éléments du tableau original si nécessaire. La notation `int tab[]` dans la déclaration de la fonction est équivalente à `int *tab`.

---

# Les tableaux

## Petite pause exercice

.cols[
.fifty[
**Exercice : Somme des éléments d'un tableau**

Écrire une fonction `int somme_tableau(int tab[], size_t taille)` qui calcule et retourne la somme des éléments d'un tableau d'entiers.
]
.fifty[
**Exercice : Trouver le maximum dans un tableau**
Écrire une fonction `int max_tableau(int tab[], size_t taille)` qui trouve et retourne le maximum dans un tableau d'entiers.
]
]

---

# Les chaînes de caractères

## Des tableaux un peu spéciaux

En `C`, une chaîne de caractères est représentée comme un tableau de caractères (`char`), terminé par un caractère nul (`'\0'`). Ce caractère spécial indique la fin de la chaîne.

```c
char message[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; // Chaîne "Hello"
```

ou bien plus simplement

```c
char message[] = "Hello"; // Chaîne "Hello", taille déduite
```

Le `'\0'` est crucial car il permet aux fonctions de la bibliothèque standard de déterminer où la chaîne se termine sans connaître sa taille à l'avance.

---

# Les chaînes de caractères

## Pointeurs et chaînes

En `C`, le nom d'un tableau de caractères (chaîne) agit comme un pointeur vers son premier élément. Par conséquent, vous pouvez manipuler les chaînes de caractères en utilisant des pointeurs.

```c
char message[] = "Hello";
char *ptr = message; // ptr pointe vers le premier caractère 'H'
printf("%c\n", *ptr); // Affiche 'H'
ptr++; // Avance le pointeur au caractère suivant
printf("%c\n", *ptr); // Affiche 'e'
```

---

# Les chaînes de caractères

## Manipulation des chaînes

En `C`, la manipulation des chaînes de caractères se fait principalement à l'aide de fonctions de la bibliothèque standard `<string.h>`. Voici quelques fonctions couramment utilisées :

| Fonction            | Description                                            |
| ------------------- | ------------------------------------------------------ |
| `strlen(s)`         | Retourne la longueur de la chaîne `s` (sans le `'\0'`) |
| `strcpy(dest, src)` | Copie la chaîne `src` dans `dest`                      |
| `strdup(s)`         | Alloue de la mémoire et copie la chaîne `s` dedans     |
| `strcat(dest, src)` | Concatène la chaîne`src`à la fin de`dest`              |
| `strcmp(s1, s2)`    | Compare les chaînes`s1`et`s2`(0 si égales)             |
| `strchr(s, c)`      | Cherche le caractère`c`dans la chaîne`s`               |

---

# Retour sur les pointeurs

## Algèbre de pointeurs

En `C`, on peut effectuer des opérations arithmétiques sur les pointeurs. Ces opérations sont basées sur la taille du type de données pointé.

```c
int tab[5] = {10, 20, 30, 40, 50};
int *p = tab; // p pointe vers tab[0]
p++; // p pointe maintenant vers tab[1]
printf("%d\n", *p); // Affiche 20
p += 2; // p pointe maintenant vers tab[3]
printf("%d\n", *p); // Affiche 40
```

Le saut d'un pointeur `p` de type `T*` de `n` positions avance l'adresse de `n * sizeof(T)` octets.

---

# Les chaînes de caractères

## Petite pause exercice

**Exercice : Compter les voyelles**
Écrire une fonction `size_t compter_voyelles(const char* str)` qui compte le nombre de voyelles dans une chaîne de caractères.

**Exercice : Inverser une chaîne**
Écrire une fonction `void inverser_chaine(char* str)` qui inverse une chaîne de caractères en place.

---

# Les structures

## Regrouper des données

En `C`, une structure (`struct`) est un type de données dérivé qui permet de regrouper plusieurs variables sous un même nom. Chaque variable à l'intérieur d'une structure est appelée un **membre** ou un **attribut**. Les structures sont utiles pour représenter des objets complexes avec plusieurs attributs. Par exemple si on veut définir un point dans un plan 2D on peut faire :

```c
struct Point {
    char label; // Étiquette du point
    int x; // Coordonnée x
    int y; // Coordonnée y
};
```

---

# Les structures

## Utilisation

L'utilisation se fait alors de la manière suivante :

```c
struct Point p1; // Déclaration d'une variable de type Point
p1.label = 'A'; // Accès aux membres
p1.x = 10;
p1.y = 20;
```

L'initialisation peut aussi se faire de la manière suivante :

```c
struct Point p2 = {'B', 30, 40}; // Initialisation lors de la déclaration
```

---

# Les structures

## Pointeurs vers des structures

En `C`, vous pouvez également créer des pointeurs vers des structures. Cela est particulièrement utile lorsque vous souhaitez manipuler des structures sans les copier, ou lorsque vous travaillez avec des fonctions.

```c
struct Point {
    char label;
    int x;
    int y;
};
struct Point p1 = {'A', 10, 20};
struct Point *ptr = &p1; // Pointeur vers la structure p1
printf("Point %c: (%d, %d)\n", ptr->label, ptr->x, ptr->y);
```

L'opérateur `->` est utilisé pour accéder aux membres d'une structure via un pointeur.

---

# Les structures

## Petite pause exercice

**Exercice : Structure Rectangle**
Définir une structure `Rectangle` avec deux points (coin supérieur gauche et coin inférieur droit). Écrire une fonction pour calculer l'aire du rectangle.

**Exercice : Structure Étudiant**
Définir une structure `Etudiant` avec des membres pour le nom, l'âge et une liste de 5 notes.

- Écrire une fonction pour afficher les informations de l'étudiant.
- Écrire une fonction pour calculer la moyenne des notes.
- Définir un tableau de 3 étudiants et afficher leurs informations ainsi que leur moyenne.
- Trier les étudiants par ordre croissant des moyennes et afficher le classement.

---

# Un premier "gros" exercice en C

**Exercice : Snake Game Simplifié**
Créer une version simplifiée du jeu Snake en utilisant des tableaux pour représenter le terrain de jeu et la position du serpent.

Je suis super sympa, je vous ai fait un squelette de code pour vous aider à démarrer.

<iframe src="https://giphy.com/embed/l0MYt5jPR6QX5pnqM" width="480" height="270" style="position: absolute; top: 55%; left: 35%; opacity: 0.2" frameBorder="0" class="giphy-embed" allowFullScreen></iframe>

Le code est disponible ici [https://github.com/ue12-p25/c-snake-starter](https://github.com/ue12-p25/c-snake-starter)

---

class: middle, center

# Séance 3 

## TP Snake 
## Séparation du code en C

---

# Pourquoi séparer un programme ?

.center[Tout simplement parce qu'on est pas des degxxxxxxe et qu'on range un peu nos affaires !]

**Avantages** :

.center[Lisibilité, Modularité ,Compilation incrémentale <br> Réutilisation de code, Encapsulation]


**Grands principes** : 

Un programme C est composé de fonctions et de variables et peut résider dans un ou plusieurs fichiers source.

L'organisation du code en plusieurs fichiers est gérée par le système de compilation et de liaison (linking), ainsi que par des règles strictes concernant la visibilité et la déclaration des identifiants partagés.


---

# Séparation .c vs .h 

Afin de simplifier la gestion des déclarations partagées et d'assurer la cohérence des types et des fonctions entre les fichiers sources, il est d'usage de regrouper les déclarations externes dans des fichiers d'en-tête (header files, qui portent généralement l'extension .h)

**Rôle des Headers** : Les fichiers d'en-tête contiennent principalement les prototypes des fonctions (déclarations de la fonction, de son type de retour et de ses arguments) et les déclarations extern des variables globales

**Inclusion** : Le fichier d'en-tête est inclus dans chaque fichier source (.c) qui utilise ces entités au moyen de la directive de préprocesseur `#include`. Cette directive a pour effet d'insérer le contenu du fichier d'en-tête directement dans le fichier source au moment de la précompilation.


.center[***L'utilisation de fichiers d'en-tête garantit que toutes les unités de compilation disposent des mêmes définitions et déclarations***]

---

# Processus de compilation 

Le processus de création d'un exécutable à partir de plusieurs fichiers sources implique généralement les étapes suivantes :

1. Compilation : Chaque fichier source (.c) est compilé individuellement en un fichier objet (.o).
2. Liaison (Linking) : Tous les fichiers objets (.o) sont ensuite liés ensemble pour produire le programme exécutable final. Le linker est chargé de résoudre toutes les références externes entre les différents modules.

L'étape de liaison est essentielle pour "connecter les occurrences" des fonctions et variables définies dans un fichier et appelées dans un autre

| Élément           | Extension | Rôle                                                     |
|-------------------|-----------|-----------------------------------------------------------|
| Fichier source    | `.c`      | Contient les définitions des fonctions et des variables. |
| Fichier d'en-tête | `.h`      | Contient les déclarations (`extern` et prototypes).      |
| Fichier objet     | `.o`      | Produit intermédiaire après compilation, prêt pour la liaison. |


---

# Include guards 

Pour éviter les inclusions multiples d'un même fichier d'en-tête, on utilise des "include guards". Cela empêche les redéfinitions et les erreurs de compilation.

Ces include guards sont généralement implémentés à l'aide de directives de préprocesseur `#ifndef`, `#define` et `#endif`.

```c
#ifndef NOM_DU_FICHIER_H
#define NOM_DU_FICHIER_H
// Contenu du fichier d'en-tête
#endif // NOM_DU_FICHIER_H
```

Il est possible aussi d'utiliser `#pragma once` qui est une directive non standard mais largement supportée par les compilateurs modernes.

---

# Concepts clés de la séparation en C
## Notions de déclaration, définition et portée 

En `C`, il est crucial de comprendre la différence entre **déclaration** et **définition**, ainsi que les concepts de **portée**/**visibilité**. 


**Déclaration** : annonce un symbole, pas d’allocation  
**Définition** : crée l’objet, réserve la mémoire


Exemples :
```c
extern int x;      // déclaration
int x = 0;         // définition
int add(int a,b);  // déclaration
int add(int a,b){ return a+b; } // définition
```

Pour déclarer une variable sans la définir, on utilise le mot-clé `extern`. Cela indique au compilateur que la variable est définie ailleurs (dans un autre fichier source).

---

# Concepts clés de la séparation en C
## Portée et visibilité 

La **portée** (scope) d'un symbole détermine où il est accessible dans le code source. La **visibilité** (linkage) détermine si un symbole peut être référencé depuis d'autres fichiers.

Pour gérer la portée et la visibilité, on utilise les mots-clés `extern` et `static`.

| Mot-clé | Effet | Portée |
|--------|-------|--------|
| (rien) | symbole externe | visible partout |
| extern | déclare sans définir | visible ailleurs |
| static | liaison interne | visible uniquement dans le fichier |

Ces mots clés permettent de contrôler l'accès aux fonctions et variables entre différents fichiers source, évitant ainsi les conflits de noms et assurant une meilleure encapsulation du code.

---

# Concepts clés de la séparation en C
## Portée et visibilité (demo)



.cols[
  .fifty[
  .smaller[

```c
#ifndef FICHIER1_H
#define FICHIER1_H
// Déclaration d'une variable globale définie ailleurs
extern int global_counter;
// Prototype d'une fonction publique
void increment_counter(void);
// Prototype d'une fonction publique utilisant une variable privée de fichier1.c
int get_hidden_value(void);
#endif
```

```c
#include "fichier1.h"
#include <stdio.h>
// Définition de la variable globale
int global_counter = 0;
// Variable privée à ce fichier (NON visible ailleurs)
static int hidden_value = 42;
// Fonction publique : visible via le header
void increment_counter(void)
{
    global_counter++;
}
// Fonction strictement privée
static void secret_function(void)
{
    printf("Hello from secret\n");
}
// Fonction publique qui lit une variable privée
int get_hidden_value(void)
{
    secret_function();
    return hidden_value;
}

```
  ]
  ]
  .fifty[
.smaller[

```c
#ifndef FICHIER2_H
#define FICHIER2_H
// variable globale déclarée ici mais définie dans fichier2.c
extern int module2_value;
// fonction publique
int compute_sum(int x);
#endif
```

```c
#include "fichier2.h"
#include "fichier1.h" // on va utiliser global_counter
// Définition d’une variable globale visible partout
int module2_value = 10;
// Variable privée au module2
static int local_buffer = 100;
// Fonction publique
int compute_sum(int x)
{
    // utilise global_counter (défini dans fichier1.c)
    return x + module2_value + global_counter;
}
// Fonction privée
static int internal_compute(int x)
{
    return x + local_buffer;
}
```
]
  ]
]

---

# Concepts clés de la séparation en C
## Portée & Linkage (demo)

.cols[.sixty[
  .smaller[
```c
#include <stdio.h>
#include "fichier1.h"
#include "fichier2.h"

int main(void)
{
    printf("global_counter = %d\n", global_counter);
    printf("module2_value  = %d\n", module2_value);

    increment_counter(); // modifie la variable globale
    printf("after increment: global_counter = %d\n", global_counter);

    printf("hidden_value (via getter) = %d\n",
           get_hidden_value()); // accès indirect OK

    int result = compute_sum(5);
    printf("compute_sum(5) = %d\n", result);

    // --- EXEMPLES INVALIDES (montrés pour la théorie) ---

    // printf("%d", hidden_value); → ERREUR : variable static invisible
    // secret_function();          → ERREUR : fonction static invisible
    // internal_compute(5);        → ERREUR : fonction static invisible

    return 0;
}
``` 

  ]
]
.fourty[
```bash
$ gcc -c fichier1.c
$ gcc -c fichier2.c
$ gcc -c main.c
$ gcc fichier1.o fichier2.o main.o -o prog
```

Si vous êtes curieux, vous pouvez vérifier les symboles visibles dans chaque fichier objet avec la commande `nm` :

```bash
$ nm fichier1.o
```
]
]

---

# Concepts clés de la séparation en C
## Résolution des symboles

Lors de la phase de linking, le linker résout les références aux symboles (fonctions et variables) entre les différents fichiers objets. Il associe chaque appel de fonction ou accès à une variable à sa définition correspondante.

Si votre programme utilise une fonction ou une variable qui n'a pas été définie dans aucun des fichiers objets, le linker génère une erreur de type "undefined reference".

Si vous utilisez des fonctions définies dans des bibliothèques externes (comme la bibliothèque standard C), vous devez également indiquer au linker où trouver ces bibliothèques. Cela se fait généralement en utilisant des options de ligne de commande lors de l'appel au compilateur. Par exemple pour utiliser la librairie mathématique `-lm` :

```bash
gcc main.o -o prog -lm
```

Pour voir les librairies liées à un exécutable, on peut utiliser la commande `ldd` :

```bash
$ ldd prog
```

---

# Notion de bibliothèque
## Pourquoi des bibliothèques ?

Les bibliothèques permettent de regrouper du code réutilisable dans des fichiers séparés, facilitant ainsi la modularité et la maintenance du code. Elles offrent plusieurs avantages :

- Réutilisation du code : les fonctions communes peuvent être utilisées dans plusieurs projets sans duplication.
- Réduction de la taille des exécutables : le code commun est stocké une seule fois
- Mise à jour facilitée : les bibliothèques peuvent être mises à jour indépendamment des applications qui les utilisent.

Surtout, elles permettent de partager du code entre plusieurs programmes.

---

# Notion de bibliothèque
## Types de bibliothèques

Il existe deux principaux types de bibliothèques en `C` :

- Bibliothèques statiques (.a) : le code de la bibliothèque est copié dans l’exécutable lors de la phase de linking. Cela rend l’exécutable autonome, mais augmente sa taille.
- Bibliothèques dynamiques (.so sur Linux, .dll sur Windows, .dylib sur macOS) : le code de la bibliothèque est chargé en mémoire au moment de l’exécution. Cela permet de partager une seule copie de la bibliothèque entre plusieurs programmes, réduisant ainsi la taille des exécutables et facilitant les mises à jour.

Chaque type de bibliothèque a ses propres avantages et inconvénients, et le choix entre les deux dépend des besoins spécifiques du projet.

---

# Notion de bibliothèque
## Création et utilisation

Pour créer et utiliser des bibliothèques en `C`, voici les étapes générales :
1. **Création de la bibliothèque** :
   - Compiler les fichiers source (.c) en fichiers objets (.o).
   - Pour une bibliothèque statique, utiliser l'outil `ar` pour créer un fichier `.a`.
   - Pour une bibliothèque dynamique, utiliser le compilateur avec l'option `-shared`.

2. **Utilisation de la bibliothèque** :
    - Inclure le fichier d'en-tête (.h) de la bibliothèque dans votre code source.
    - Lors de la compilation, spécifier le chemin vers la bibliothèque et son nom avec les options `-L` (chemin) et `-l` (nom).

Au runtime, il peut être nécessaire de configurer les chemins de recherche des bibliothèques dynamiques. Cele se se fait via des variables d'environnement ou des options de compilation spécifiques, par exemple `LD_LIBRARY_PATH`.

---

# Notion de bibliothèque
## Bibliothèque statique vs dynamique

.cols[
  .fifty[
    **Statique**

```bash 
$ gcc -c fichier1.c
$ gcc -c fichier2.c
$ ar rcs libmylib.a fichier1.o fichier2.o
```
Utilisation 
```bash
$ gcc main.o -L. -lmylib
```

  ]

.fifty[
  **Dynamique**
```bash 
$ gcc -c -fPIC fichier1.c
$ gcc -c -fPIC fichier2.c
$ gcc -shared fichier1.o fichier2.o -o libmylib.so
```
Utilisation 
```bash
$ gcc main.o -L. -lmylib
```
]
]

.center[A vous de regarder ce que ca change ! Notamment au niveau de la taille de l’exécutable et de la gestion des mises à jour.]

---

# Programme des séances

.cols[

.fifty[

- Séance 1 : 28/10

  - Toute la base du C,
  - variables, types,
  - branchements, boucles,
  - fonctions

- Séance 2 : 04/11

  - Types dérivés : tableaux, struct, pointeurs
  - Coding style et clean code

- Séance 3 : 09/12

  - LA mémoire

- Séance 4 : 16/12

  - La librairie standard C

]
.fifty[

- Séance 5 : 06/01

  - Astuces avancées : préprocesseur, macro
  - Industrialisation : chaînes de compilation

- Séance 6 : 13/01

  - Utilisation de librairies externes
  - GNU Scientific Library
  - SDL

- Séance 7 : 20/01

  - Tests unitaire
  - Profiling de code

- Séance 8 : 21/01

  - Gestion des erreurs

- Séance 9 : 27/01

  - Projet
    ]

]

<div style="position: absolute; top: 53%; left: 31%;opacity: 0.2">
<iframe src="https://giphy.com/embed/okFG5aJWqRGMYXoKTD" width="280" height="280" style="" frameBorder="0" class="giphy-embed" allowFullScreen></iframe>
</div>

<div style="position: absolute; top:50%; left:75%; opacity: 0.2">
<iframe src="https://giphy.com/embed/GghGKaZ8JeHJx0apQC" width="280" height="280" style="" frameBorder="0" class="giphy-embed" allowFullScreen></iframe>
</div>

---
