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
        <span>2025 - <i> Introduction au C ? ✨ </i>  </span> <span id="footerlinks"> Goto Séance <a href="#2">1</a>/<a href="#56">2</a>/<a href="#79">3</a>/<a href="#93">4</a>/<a href="#114">5</a>/<a href="#138">6</a>/<a href="#149">7</a> </span>
    </div>
    <a >
</div>

<div class="linkedin-footer">
<a href="https://www.linkedin.com/in/basilemarchand/" target="_blank" class="linkedin-badge">
  <img src="https://cdn-icons-png.flaticon.com/512/174/174857.png" alt="LinkedIn logo">
  <span>@basilemarchand</span>
</a>
</div>

<div class="slide-decor"></div>



---

class: center, middle

# Séance 1

## Les bases du langage


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

class: center, middle

# Séance 4

## **LA** mémoire en C

---

# La mémoire en C 

Ca y est on arrive enfin **au** sujet le plus important en C : la gestion de la mémoire !

Vous allez me dire "Mais on a déjà parlé de mémoire avec les variables et les pointeurs non ?" 

Oui et non. Jusqu'à présent on a surtout parlé de la mémoire **statique**, i.e. celle que l'on est capable de dimensionner à la compilation. 

Mais on a également besoin de mémoire **dynamique**, i.e. que l'on peut allouer et libérer à l'exécution, en fonction des besoins du programme. Et cette mémoire dynamique ca va être votre responsabilité en C !

---

# La mémoire en C 
## Types de mémoire 

En `C`, la mémoire est généralement divisée en plusieurs segments principaux :
.cols[
  .seventy[
- Stack (pile) : utilisé pour les variables locales et les appels de fonctions. La mémoire est allouée et libérée automatiquement lorsque les fonctions sont appelées et retournées.
- Heap (tas) : utilisé pour la mémoire dynamique allouée via `malloc`, `calloc`, `realloc` et libérée avec `free`. La gestion de cette mémoire est manuelle.
- BSS : segment pour les variables globales et statiques non initialisées.
- Data : segment pour les variables globales et statiques initialisées.
- Text : segment pour le code exécutable et les constantes.

  ]
  .thirty[.smaller[
```
+------------------------+
| Stack (pile)           |
| - variables locales    |
| - frames d'appel       |
+------------------------+
|        ↓               |
|        ↑               |
| Heap (tas)             |
| - malloc / free        |
+------------------------+
| BSS                    |
| - globales non init    |
+------------------------+
| Data                   |
| - globales init        |
+------------------------+
| Text                   |
| - code                 |
| - constantes           |
+------------------------+

```
  ]
  ]
]

---
# La mémoire en C
## La stack (pile)

La stack (pile) est une région de la mémoire utilisée pour stocker les variables locales et les informations de contrôle des fonctions (comme les adresses de retour). La gestion de la pile est automatique : lorsque vous entrez dans une fonction, un nouveau "frame" est créé sur la pile, et lorsque vous quittez la fonction, ce frame est détruit.

.center[**Caractéristiques de la stack**]
- Allocation et libération rapide.
- Taille limitée (dépend du système).
- Accès en LIFO (Last In, First Out).

La stack correspond à la mémoire dimensionnable à la compilation. 

---

# La mémoire en C
## Text, Data et BSS segment 

Les segments Text, Data et BSS sont des parties spécifiques de la mémoire utilisées pour stocker différents types de données dans un programme C. 

.cols[
  .fifty[
.center[**Segment Text**]
- Contient le code exécutable du programme.
- Généralement en lecture seule pour éviter les modifications accidentelles.
.center[**Segment Data**]
- Contient les variables globales et statiques initialisées.
- La taille est déterminée à la compilation.
.center[**Segment BSS**]
- Contient les variables globales et statiques non initialisées.
- Initialisé à zéro au démarrage du programme.
  ]
  .fifty[

  ]
]

---

# La mémoire en C
## Pour le fun - voir la mémoire 

Vous pouvez visualiser les différents segments mémoire d'un programme en utilisant des outils comme `gdb` ou `objdump`.
.cols[
.fifty[
```bash
$ gcc -g -o mon_programme mon_programme.c
$ gdb mon_programme
(gdb) info files
...
        0x0000000000001060 - 0x000000000000119b is .text
        0x000000000000119c - 0x00000000000011a9 is .fini
        0x0000000000002000 - 0x0000000000002008 is .rodata
...
        0x0000000000004000 - 0x0000000000004018 is .data
        0x0000000000004018 - 0x0000000000004028 is .bss
```
]
.fifty[
```bash
$ objdump -h mon_programme
mon_programme:     file format elf64-x86-64
Sections:
 15 .text         0000013b  0000000000001060  0000000000001060  00001060  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
...
 17 .rodata       00000008  0000000000002000  0000000000002000  00002000  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
...
 24 .data         00000018  0000000000004000  0000000000004000  00003000  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 25 .bss          00000010  0000000000004018  0000000000004018  00003018  2**2
                  ALLOC
```
]
]

---

# La mémoire en C
## Voir les symboles

Une autre façon de voir où sont stockées les différents symboles est d'utiliser la commande `nm` :

.smaller[
.cols[
  .fifty[
```c
#include <stdio.h>

int global_init = 42;       // DATA (initialisé)
static int static_init = 7; // DATA (initialisé)

int global_uninit;        // BSS (0 implicite)
static int static_uninit; // BSS (0 implicite)

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    printf("%d\n", add(global_init, global_uninit));
    return 0;
}

```
  ]
  .fifty[
```bash
$ nm demo
...
0000000000004018 B __bss_start
...
0000000000004000 D __data_start
...
0000000000001060 T _start
0000000000001149 T add
...
0000000000004010 D global_init
000000000000401c B global_uninit
0000000000001161 T main
                 U printf@GLIBC_2.2.5
00000000000010c0 t register_tm_clones
0000000000004014 d static_init
0000000000004020 b static_uninit
```

| Lettre    | Segment | Signification                     |
| --------- | ------- | --------------------------------- |
| `T` / `t` | TEXT    | Code (fonctions)                  |
| `D` / `d` | DATA    | Données globales initialisées     |
| `B` / `b` | BSS     | Données globales non initialisées |
| `R` / `r` | RODATA  | Lecture seule (constantes)        |
| `U`       | —       | Symbole externe (librairie)       |
| `W` / `w` | —       | Weak symbol                       |


  ]
]
]

---
# La mémoire en C 
## La heap (tas)

Ca y est on arrive enfin à la mémoire dynamique : la heap (tas) !




Car oui, dans beaucoup de cas on ne peut pas savoir à l'avance combien de mémoire on va avoir besoin. Par exemple si on lit un fichier dont on ne connait pas la taille, ou si on veut créer une structure de données dont la taille peut varier à l'exécution (liste chaînée, arbre, etc.). Si on veut faire de l'algèbre linéaire avec des matrices dont la taille est définie par l'utilisateur, on ne peut pas dimensionner ces matrices à la compilation.

---

# La mémoire en C
## Gestion de la mémoire dynamique

Pour gérer la mémoire dynamique en `C`, on utilise les fonctions suivantes de la bibliothèque standard `<stdlib.h>` :
- `malloc(size_t size)` : alloue un bloc de mémoire de `size` octets et retourne un pointeur vers le début de ce bloc. La mémoire n'est pas initialisée.
- `calloc(size_t num, size_t size)` : alloue un bloc de mémoire pour `num` éléments de `size` octets chacun et initialise tous les octets à zéro.
- `realloc(void *ptr, size_t size)` : redimensionne un bloc de mémoire précédemment alloué pointé par `ptr` à une nouvelle taille `size`. Si la nouvelle taille est plus grande, le contenu existant est préservé.
- `free(void *ptr)` : libère un bloc de mémoire précédemment alloué pointé par `ptr`.

---

# La mémoire en C
## Comment connaitre la taille a allouer ?

Vous vous dites peut-être "Ok, mais comment je sais combien de mémoire j'ai besoin ?" ... Pas de problème, on a des astuces pour ça !

La fonction `sizeof` permet de connaitre la taille en octets d'un type ou d'une variable. Par exemple :

```c
sizeof(int);        // Taille d'un int
sizeof(double);     // Taille d'un double
sizeof(struct Point); // Taille d'une structure Point
``` 

On peut donc utiliser `sizeof` pour allouer la bonne quantité de mémoire. Par exemple, pour allouer un tableau de `n` entiers :

```c
int *tab = malloc(n * sizeof(int));
``` 

---

# La mémoire en C
## Exemple d'utilisation

.smaller[
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t n = 5;
    // Allouer un tableau de n entiers
    int *tab = malloc(n * sizeof(int));
    if (tab == nullptr) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }

    // Initialiser et afficher le tableau
    for (size_t i = 0; i < n; i++) {
        tab[i] = i * 10;
        printf("%d ", tab[i]);
    }
    printf("\n");

    // Libérer la mémoire allouée
    free(tab);
    return 0;
}
```
]


---

# La mémoire en C
## Durée de vie != Portée 

**Attention**, la durée de vie d'une variable allouée dynamiquement (sur le tas) est indépendante de sa portée (scope). Par exemple :
.cols[
  .fifty[
```c
void fonction() {
    int *ptr = malloc(sizeof(int)); 
    *ptr = 42;
    // ptr est valide ici
}
// ptr sort de la portée ici
// mais la mémoire allouée reste valide
```
  ]
.fifty[
***Félicitations ! Vous venez de créer une fuite mémoire !***
.def[
La mémoire allouée avec `malloc` (ou `calloc`, `realloc`) reste valide jusqu'à ce qu'elle soit libérée avec `free`, même si le pointeur qui la référence sort de la portée.
]
]
]

--

.center.clignote[
  **A chaque `malloc` doit correspondre un seul et unique `free` !**
]

---

# La mémoire en C
## Allocation et structures 

.cols[
  .fifty[
Considérons pour commencer une structure simple représentant un point dans un plan 2D. 

  ]
  .fifty[
.smaller[
```c
struct Point {
    int x;
    int y;
};
typedef struct Point Point;
```
  ]

  ]
  ]

.cols[
  .fifty[

Si maintenant on veut allouer un tableau de `n` points, on peut faire comme suit :

  ]

.fifty[
.smaller[
```c 
Point *points = malloc(n * sizeof(Point));
for (size_t i = 0; i < n; i++) {
    points[i].x = i;
    points[i].y = i * 2;
}
```
]
]
]


.cols[
  .fifty[ 
.smaller[
```c
int *tmp = realloc(points, new_size * sizeof(Point));
if(tmp != nullptr) {
    points = tmp;
} else {
    // gérer l'erreur d'allocation
}

```
]
]
  .fifty[
Si on veut faire grandir dynamiquement ce tableau, on peut utiliser `realloc`. 
  ]
]


.cols[
  .fifty[ 
```c
free(points);
```

  ]
  .fifty[
    Il ne faut pas oublier à la fin de libérer la mémoire allouée. 
  ]
]

---

# La mémoire en C 
## Allocation de mémoire pour des pointeurs dans des structures

Il est bien évidemment possible d'avoir des pointeurs dans des structures. Dans ce cas, il faut allouer la mémoire pour ces pointeurs séparément. 

.cols[.fourty[
Par exemple, considérons une structure représentant une liste d'entiers : 
]
.sixty[

```c
struct IntList {
    size_t size;   // nombre d'éléments
    int *data;     // pointeur vers les données
};
typedef struct IntList IntList;
```

]]

.cols[
  .fifty[
Pour initialiser une telle structure, on peut faire comme suit :

  ]
  .fifty[
```c
IntList list;
list.size = n;
list.data = malloc(n * sizeof(int));
```

  ]
]

```c
// N'oubliez pas de libérer la mémoire plus tard
free(list.data);
```


---

# La mémoire en C
## Allocation de mémoire pour des pointeurs dans des structures (suite)

En pratique, on encapsule souvent cette logique dans des fonctions dédiées pour créer et libérer ces structures.


.smaller[
.cols[.fifty[
```c
IntList* create_int_list(size_t n) {
    IntList *list = malloc(sizeof(IntList));
    if (list == nullptr) return nullptr;
    list->size = n;
    list->data = malloc(n * sizeof(int));
    if (list->data == nullptr) {
        free(list);
        return nullptr;
    }
    return list;
}
```

]
.fifty[
```c
void free_int_list(IntList *list) {
    if (list != nullptr) {
        free(list->data);
        free(list);
    }
}
``` 
]
]
]

```c 
int main(){
    IntList *my_list = create_int_list(10);
    // Utilisation de my_list
    free_int_list(my_list);
    return 0;
}
```

---

# La mémoire en C
## Les erreurs courantes

En `C`, la gestion manuelle de la mémoire peut entraîner plusieurs types d'erreurs courantes :

- *Fuites de mémoire* : oublier de libérer la mémoire allouée avec `free`, ce qui conduit à une consommation excessive de mémoire.
- *Double libération* : appeler `free` plusieurs fois sur le même pointeur, ce qui peut provoquer des comportements indéfinis.
- *Utilisation de mémoire* libérée : accéder à de la mémoire après l'avoir libérée, ce qui peut entraîner des plantages ou des données corrompues.
- *Débordement de mémoire* : écrire au-delà des limites d'un bloc de mémoire alloué, ce qui peut corrompre d'autres données.
- *Non-vérification des retours d'allocation* : ne pas vérifier si `malloc`, `calloc` ou `realloc` ont réussi, ce qui peut conduire à des accès à des pointeurs nuls.


---
# La mémoire en C
## Outils de détection et bonnes pratiques

Pour éviter et détecter les erreurs de gestion de mémoire en `C`, plusieurs outils et bonnes pratiques peuvent être utilisés :

- *Valgrind* : un outil populaire pour détecter les fuites de mémoire, les accès invalides et d'autres erreurs liées à la mémoire.
- *AddressSanitizer* : un outil de détection des erreurs de mémoire intégré dans les compilateurs modernes comme GCC et Clang.
- *Initialisation des pointeurs* : toujours initialiser les pointeurs à `NULL` (ou `nullptr`) après la déclaration.
- *Vérification des allocations* : toujours vérifier le retour de `malloc`, `calloc` et `realloc` avant d'utiliser le pointeur retourné.
- *Libération systématique* : s'assurer que chaque allocation a une libération correspondante.
- *Utilisation de fonctions dédiées* : encapsuler la logique d'allocation et de libération dans des fonctions pour réduire les erreurs.

---


# Pause exercice

**Exercice : Gestion de mémoire avec des structures**

.smaller[
```c
struct Matrix {

    size_t rows;
    size_t cols;
    double **data; // Pointeur vers un tableau de pointeurs
};
typedef struct Matrix Matrix;

```
]

- Écrire une fonction `Matrix* create_matrix(size_t rows, size_t cols)` qui alloue dynamiquement une matrice de dimensions `rows x cols`.
- Écrire une fonction `void free_matrix(Matrix* mat)` qui libère la mémoire allouée pour la matrice.
- Écrire une fonction `void set_value(Matrix* mat, size_t row, size_t col, double value)` pour définir la valeur d'un élément de la matrice.
- Écrire une fonction `double get_value(const Matrix* mat, size_t row, size_t col)` pour obtenir la valeur d'un élément de la matrice.
- écrire une fonction `Matrix* product(const Matrix* a, const Matrix* b)` qui calcule le produit de deux matrices.


---

# Pause exercice (suite)

**Exercice : Gestion de mémoire avec des structures (suite)**

.cols[
  .fifty[
On va faire un évaluateur simple d'expressions arithmétiques en utilisant des arbres binaires.

  ]
  .fifty[
.smaller[
```c
struct Node {
    char operator; // '+', '-', '*', '/' ou '\0' pour les feuilles
    char var_name; // nom de la variable pour les feuilles
    double value;  // valeur pour les feuilles
    struct Node *left;
    struct Node *right;
};
typedef struct Node Node;
```
]
  ]
]


- Écrire une fonction `Node* create_leaf(double value)` qui crée une feuille avec une valeur donnée.
- Écrire une fonction `Node* create_operator_node(char operator, Node* left, Node* right)` qui crée un nœud opérateur avec deux sous-arbres.
- Écrire une fonction `Node* create_variable_node(char var_name)` qui crée une feuille représentant une variable.
- Écrire une fonction `double evaluate(const Node* root, Context* ctx)` qui évalue l'expression représentée par l'arbre.
- Écrire une fonction `void free_tree(Node* root)` qui libère la mémoire allouée pour l'arbre.


---

# Pause exercice (fin)

On veut pouvoir faire des choses comme ça :
.smaller[

```c
int main(){
  // Exemple 1: 2*x + 3
  //Arbre:      +
  //          /   \
  //         *     3
  //        / \
  //       2   x
  //
  printf("Exemple 1: 2*x + 3\n");
  Node *expr1 = create_operator_node('+',
                              create_operator_node('*',
                                            create_leaf(2),
                                            create_variable_node('x')),
                              create_leaf(3));

  Context *ctx = context_create();
  context_set(ctx, 'x', 5);
  printf("  avec x=5: 2*5 + 3 = %.2f\n", evaluate(expr1, ctx));

  context_set(ctx, 'x', 10);
  printf("  avec x=10: 2*10 + 3 = %.2f\n\n", evaluate(expr1, ctx));

  node_free(expr1);
  context_free(ctx);
  return 0; 
}
```
]


---

class: middle, center

# Séance 5

## Aspects un peu plus avancés


---

# Le mot clé `static`
## 3 usages principaux

En `C`, le mot-clé `static` a plusieurs usages selon le contexte dans lequel il est utilisé :

1. **Variables locales** : Lorsqu'une variable locale est déclarée avec `static`, sa durée de vie est étendue à toute la durée du programme, mais sa portée reste limitée à la fonction dans laquelle elle est définie. Cela signifie que la variable conserve sa valeur entre les appels de fonction.

2. **Variables globales** : Lorsqu'une variable globale est déclarée avec `static`, sa portée est limitée au fichier source dans lequel elle est définie. Cela empêche d'autres fichiers de référencer cette variable, ce qui aide à éviter les conflits de noms.

3. **Fonctions** : Lorsqu'une fonction est déclarée avec `static`, sa portée est également limitée au fichier source dans lequel elle est définie. Cela empêche la fonction d'être appelée depuis d'autres fichiers, ce qui est utile pour encapsuler des fonctions utilitaires.

---

# Le mot clé `static`
## Durée de vie des variables statiques

.cols[
  .seventy[
```c
#include <stdio.h>
void compteur() {
    static int count = 0; // Variable statique locale
    count++;
    printf("Compteur: %d\n", count);
}

int main() {
    for (int i = 0; i < 5; i++) {
        compteur();
    }
    return 0;
}
```
  ]
  .thirty[
**Sortie :**
```shell
$ ./a.out 
Compteur: 1
Compteur: 2
Compteur: 3
Compteur: 4
Compteur: 5
```
  ]
]

---

# Le mot clé `static`
## Singleton pattern en C

Le mot-clé `static` peut être utilisé pour implémenter le pattern Singleton en `C`, garantissant qu'une seule instance d'une structure ou d'un objet est créée et accessible globalement.
.smaller[
.cols[
  .fifty[
```c
#include <stdlib.h>
#include <stdio.h>

typedef struct S
{
    int a;
    double b;
} S;

S *singleton()
{
    static S s_instance = {.a = 42, .b = 3.14};
    return &s_instance;
}

void print_s(S s[static 1])
{
    printf("{.a = %d, S.b = %.2f} @ %p\n", s->a, s->b, (void *)s);
}
```
  ]
  .fifty[
```c

int main()
{
    S *s = singleton();
    print_s(s);

    s->a += 1;
    s->b *= -1.0;
    S *s2 = singleton();
    print_s(s2);

    return EXIT_SUCCESS;
}
``` 

```shell
./a.out
{.a = 42, S.b = 3.14} @ 0x562eee363020
{.a = 43, S.b = -3.14} @ 0x562eee363020
```
  ]
]
]

---

# Le mot clé `inline`
## Fonctions inline

Le mot-clé `inline` en `C` est utilisé pour suggérer au compilateur d'insérer le code de la fonction directement à l'endroit où elle est appelée, plutôt que de faire un appel de fonction traditionnel.

C'est notamment utile pour les petites fonctions qui sont appelées fréquemment. Il est indispensable de déclarer les fonctions `inline` quand vous les définissez dans un fichier d'en-tête (`.h`), afin d'éviter les erreurs de linkage.

.smaller[
.cols[
  .sixty[
```c 
#include <stdio.h>

static inline int add(int a, int b)
{
    return a + b;
}
int compute(int x)
{
    int s = 0;
    for (int i = 0; i < x; ++i)
    {
        s += add(i, x);
    }
    return s;
}
```
]
.fourty[
```c
int main(void)
{
    printf("%d\n", compute(100));
    return 0;
}
```
]
]
]

---

# Le mot clé `inline`
## Comment s'en convaicre ? 

une solution, un peu artisanale, pour voir si une fonction a bien été inlinée est de regarder le code assembleur généré par le compilateur. (Soit en générant le .s via `gcc -S`, soit en utilisant un outil en ligne comme Godbolt).

<iframe width="1000px" height="400px" src="https://godbolt.org/e?readOnly=true&hideEditorToolbars=true#z:OYLghAFBqd5QCxAYwPYBMCmBRdBLAF1QCcAaPECAMzwBtMA7AQwFtMQByARg9KtQYEAysib0QXACx8BBAKoBnTAAUAHpwAMvAFYTStJg1AB9U8lJL6yAngGVG6AMKpaAVxYM9DgDJ4GmADl3ACNMYhAAJmkAB1QFQlsGZzcPPVj4mwFffyCWUPCoi0wrTIYhAiZiAmT3Ty4iksTyyoJswJCwyOkFCqqa1Pqelrbc/K6ASgtUV2Jkdg4AegWAagJMHuM/Wj9MADpkAFINAEEDiIBmP2Q3LGWD88ce/FRdhHvsI9OToZtkZa2dv9BMtkK4eqgWMYmOh0BA/ARlkxSECEcFxp8DgB2ABCn2W%2BOWxEwBBmDERdwi2OWwXuuJOWIAIhiTvCQRDoq41nDgap0fScXiCayFHdzgzlhpaYL8fxiMtuQi8KLxZLzlSlfdHMtVLSKbjKXg%2BccCXcBScTSaRWdcWKQWCiJDobC8MjeVLzQTGdLCcTScsFO7TpimfSWcCWEw/BAAG6oPDoI1YunGgnRYjwqgQM4RM4AVnQB1zjgY2eRaBYHK5XA0GnG6LV3qJJOIZNVya9Jw4k1onFzvE8HC0pFQnC1Cmms0wFPOPFIBE0XcmAGsQOdc7sAJwaCIac4byR7gAch64XAi%2Bk4kn7C%2BHnF4ChAGjnC8mcFgSHL0ToYXIlE/3/CZBgC4XNzxoWg1mIB8IGCG9gj8SoAE9OFneDmGIRCAHlgm0TBrBQ3hyzYQRMIYWhkMHXgsGCVxgEcMRaAfbgqMwCMjHESjSHwIlrDwaN1hvTBVDwzl5lneFigI/Q8GCYgkOcLAbwIdMWCk/jiGCOJMAZVjDGAbYjBfPgDGABQADU8EwAB3TDokYKT%2BEEEQxHYKQZEERQVHUTjdHqAxDNMYxzG2YIH0gSZUGiUomIAWkwodUHU9MsDCiBJksPDSnsBgnBcWovBykYOnCep0gSAR%2BjqUgytKIq8k6QZikyppemqPKBgaZqBGaKo6rGQZWsqvQhl6nZRga9KJzmCRu17a9OJHDhtUPAA2GKVskZZgGQP4QN2CJ5VwQgSGnLhxl4edKLrUgV3Oc59o3Q9zhWo9VvOQ8NEPC8OCvUgBwSu8LEfZ8rtIN9EBQdkAN/CB/3oQDgNAvg6Eg6DYM4tCkKkzGMOw3D8OY0giMYAhSPIm9qNo%2BjaEYqSsDY/T5iHbjmv4pihyEkS1ikiSe04kK5IwhSmYulS1LCTSlB0hmDNAUGqBM8zLJsuyB1nRzhFEcQ3I1zy1BvXRz38kwzGk0L4AiqLElizCIl4RKwmSgTws63i7AgBwhurUgfDG4qQC%2BmrEi9p8g6yP36vCL6MrdspBvauonxj0oetaCOxmj%2BOUkTixWr6zpD0mmZprO76%2Bz%2Bm9FuWtaNq2nblj2g6ICOog5TOGdzpBrRrtujRdkxDcN1zDcVtzTEpA%2Br6%2Bd%2B/77cBh8n0u7vZo4O2K4WwGl8XUh1PiOxJCAA%3D%3D"></iframe>

---

# Le mot clé `inline`
## Limitations et conseils

- Le mot-clé `inline` est une suggestion au compilateur, qui peut choisir de ne pas l'appliquer.
- L'utilisation excessive de fonctions `inline` peut augmenter la taille du code binaire (code bloat).
- Il est préférable d'utiliser `inline` pour les fonctions petites et fréquemment appelées.
- Les fonctions `inline` doivent être définies dans les fichiers d'en-tête pour être accessibles dans plusieurs fichiers source.

Et attention, `inline` ne remplace pas de faire du profiling pour identifier les vrais goulots d'étranglement !

---

# Les macros en C
## Introduction aux macros

Les macros en `C` sont des directives de préprocesseur qui permettent de définir des constantes, des fonctions ou des blocs de code réutilisables. Elles sont définies à l'aide de la directive `#define` et sont remplacées par le préprocesseur avant la compilation du code source.

```c
#define PI 3.14159
#define SQUARE(x) ((x) * (x))
```


---

# Les macros en C
## Avantages et inconvénients

**Avantages :**
- Réutilisabilité : les macros permettent de réutiliser du code sans duplication.
- Flexibilité : elles peuvent être utilisées pour créer des fonctions génériques.
- Performance : les macros peuvent éviter le surcoût d'un appel de fonction.

**Inconvénients :**
- Lisibilité : le code utilisant des macros peut être plus difficile à lire et à comprendre.
- Débogage : les erreurs dans les macros peuvent être difficiles à tracer.
- Portée : les macros n'ont pas de portée de variable, ce qui peut entraîner des conflits de noms.
- Sécurité : les macros peuvent introduire des comportements inattendus si elles ne sont pas utilisées correctement.

---

# Les macros en C
## Attention au piège !

.smaller[
.cols[
  .fifty[
```c
#define SQUARE(x) x * x

int main(){
    int a = 5;
    int result = SQUARE(a + 1); 
    printf("Result: %d\n", result);
    return 0;
}
```
  ]
  .fifty[
**Sortie :**
```shell
$ ./a.out
Result: 11
```
  ]
]
]

Et oui c'est le drame !!! Ici, `SQUARE(a + 1)` est remplacé par `a + 1 * a + 1`, ce qui donne `5 + 1 * 5 + 1 = 11` au lieu de `36`. Car le préprocesseur ne comprend pas les priorités des opérations et comme son nom l'indique, il fait juste du traitement de texte en amont de la compilation.

La solution est d'utiliser des parenthèses dans la définition de la macro :

```c
#define SQUARE(x) ((x) * (x))
``` 

---

# Les macros en C
## Macros avec des arguments multiples

.smaller[
```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main(){
    int x = 10;
    int y = 20;
    int max_value = MAX(x, y);
    printf("Max: %d\n", max_value);
    return 0;
}
```
]

On peut également passer en "argument" des types, par exemple pour définir `STATIC_CAST` qui permet de faire des cast statiques  :

```c
#define STATIC_CAST(type, value) ((type)(value))

int main(){
    double d = 3.14;
    int i = STATIC_CAST(int, d);
    printf("i: %d\n", i);
    return 0;
}
```

---

# Les macros en C
## Macros avec des blocs de code 

On peut également définir des macros qui contiennent des blocs de code. Pour cela, on utilise généralement la construction `do { ... } while (0)` pour s'assurer que la macro se comporte comme une instruction unique.

Par exemple, une macro pour débuguer :

```c
#define TRACE(fmt, ...) do {                                \
    fprintf(stderr, "[%s:%d] " fmt "\n",                   \
            __FILE__, __LINE__, __VA_ARGS__);              \
} while (0)
```

.cols[
  .fifty[

```c
int main(){
    int x = 42;
    TRACE("La valeur de x est %d", x);
    return 0;
}
```
  ]
  .fifty[
**Sortie :**
```shell
$ ./a.out
[main.c:10] La valeur de x est 42
```
  ]
]


---

# Les macros en C
## Macros conditionnelles

Les macros conditionnelles permettent d'inclure ou d'exclure du code en fonction de certaines conditions. Cela est souvent utilisé pour gérer la portabilité entre différentes plateformes ou pour activer/désactiver des fonctionnalités de débogage.

.cols[
  .fifty[
```c
#if defined(Darwin)
    // Code spécifique à macOS
#else if defined(_WIN32)
    // Code spécifique à Windows
#else
    // Code pour les autres plateformes
#endif
```
  ]
  .fifty[
```c
#ifdef DEBUG
    #define LOG(msg) fprintf(stderr, "DEBUG: %s\n", msg)
#else
    #define LOG(msg) // Ne rien faire
#endif
```
]
]

Pour compiler avec la macro `DEBUG` définie, on peut utiliser l'option `-DDEBUG` avec `gcc` :

```bash
gcc -DDEBUG -o mon_programme mon_programme.c
```


---

# Les macros en C
## Poussé à l'extrême

.smaller[
.cols[
  .sixty[
```c
#define DEFINE_VECTOR(type, name)                                      \
typedef struct {                                                       \
    type *data;                                                        \
    size_t size;                                                       \
    size_t capacity;                                                   \
} vector_##name;                                                       \
                                                                       \
static inline void vector_##name##_init(vector_##name *v) {            \
    v->data = NULL;                                                    \
    v->size = 0;                                                       \
    v->capacity = 0;                                                   \
}                                                                      \
                                                                       \
static inline void vector_##name##_push_back(vector_##name *v, type x) {\
    if (v->size == v->capacity) {                                      \
        v->capacity = v->capacity ? v->capacity * 2 : 4;              \
        v->data = realloc(v->data, v->capacity * sizeof(type));       \
    }                                                                  \
    v->data[v->size++] = x;                                            \
}                                                                      \
                                                                       \
static inline void vector_##name##_free(vector_##name *v) {             \
    free(v->data);                                                     \
    v->data = NULL;                                                    \
    v->size = v->capacity = 0;                                         \
}

```
  ]
  .fourty[
```c
DEFINE_VECTOR(int, int)
int main(){
    vector_int vec;
    vector_int_init(&vec);
    for (int i = 0; i < 10; i++) {
        vector_int_push_back(&vec, i);
    }
    for (size_t i = 0; i < vec.size; i++) {
        printf("%d ", vec.data[i]);
    }
    printf("\n");
    vector_int_free(&vec);
    return 0;
}
```

En `C++`, on utiliserait plutôt des templates pour ce genre de choses, mais en `C` les macros permettent d'atteindre un résultat similaire.
]
]
]

---

# Les pointeurs de fonction 
## Introduction aux pointeurs de fonction

En `C`, un pointeur de fonction est une variable qui stocke l'adresse d'une fonction. Cela permet de passer des fonctions comme arguments à d'autres fonctions, de créer des tableaux de fonctions, et de définir des callbacks.

---

# Les pointeurs de fonction
## Déclaration et utilisation

Il faut d'abord déclarer un pointeur de fonction en spécifiant le type de retour et les types des paramètres de la fonction pointée. Par exemple, pour une fonction qui prend deux `int` en paramètres et retourne un `int` :

```c
typedef int (*FuncPtr)(int, int);
```

Cela nous donne donc accès à un nouveau type `FuncPtr` qui peut être utilisé pour déclarer des pointeurs de fonction. On peut ensuite assigner l'adresse d'une fonction à ce pointeur et l'utiliser pour appeler la fonction.

.smaller[
```c
#include <stdio.h>
int add(int a, int b) {
    return a + b;
}

int main() {
    FuncPtr func_ptr = add; // Assignation de l'adresse de la fonction
    int result = func_ptr(5, 3);     // Appel de la fonction via le pointeur
    printf("Result: %d\n", result);
    return 0;
}
```
]

---

# Les pointeurs de fonction
## Tableaux de pointeurs de fonction

On peut également créer des tableaux de pointeurs de fonction pour stocker plusieurs fonctions ayant la même signature. Cela est utile pour implémenter des tables de dispatch ou des callbacks.
.smaller[
.cols[
  .sixty[
```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    FuncPtr operations[2] = {add, multiply}; // Tableau de pointeurs de fonction

    int a = 5, b = 3;
    for (int i = 0; i < 2; i++) {
        int result = operations[i](a, b); // Appel de la fonction via le pointeur
        printf("Result: %d\n", result);
    }
    return 0;
}
```
]
.fourty[
vous pourriez utiliser ce genre de mécanisme pour faciliter l'implémentation de l'évaluateur d'expressions arithmétiques vu précédemment.
]]]

---

# Les deux derniers types de base 
## Le type `enum`

En `C`, un `enum` (énumération) est un type de données défini par l'utilisateur qui permet de regrouper un ensemble de constantes entières sous un même nom. Chaque constante dans une énumération est associée à une valeur entière unique, généralement commençant à 0 et incrémentée de 1 pour chaque élément suivant, sauf si des valeurs spécifiques sont assignées.

.smaller[
```c
#include <stdio.h>
enum Color {
    RED,    // 0
    GREEN,  // 1
    BLUE    // 2   
};
typedef enum Color Color;
int main() {
    Color my_color = GREEN;
    if (my_color == GREEN) {
        printf("La couleur est verte.\n");
    }
    return 0;
}
```
]

---

# Les deux derniers types de base 
## Limitation des enums de base 

Considérons par exemple un enum qui nous permette de spéficier les outputs d'un programme. 
.cols[
  .fifty[
```c
enum OutputMode{
  OUTPUT_NONE,
  OUTPUT_TEXT,
  OUTPUT_BINARY,
  OUTPUT_SCREEN
};
``` 
  ]
.fifty[
On ne peut facilement dans ce cas spécifier une sortie binaire + écran par exemple. 
]
]

La seule solution serait alors de définir un nouveau champ dans le enum. Ce qui n'est pas super maintenable et évolutif. 

---
 
# Les deux derniers types de bases 
## Un usage un peu particulier des enum -> les flags 

Heureusement le `C` a pensé à tout. Il est possible de spéficier les valeurs et d'utiliser le décalage de bit. 

.cols[
  .fifty[
```c
typedef enum {
    OUTPUT_NONE   = 0,
    OUTPUT_TEXT   = 1 << 0,
    OUTPUT_BINARY = 1 << 1,
    OUTPUT_SCREEN = 1 << 2
} OutputModes;
```
  ]
  .fifty[
De cette manière les valeurs valents respectivement 0, 1, 2, 4. Et surtout on peut créer une valeur comme la combinaison de plusieurs flags. 
  ]
]

.smaller[
```c
OutputModes o = OUTPUT_TEXT | OUTPUT_SCREEN;
print(o);
o = o ^ OUTPUT_TEXT;
print(o)
if (o & OUTPUT_SCREEN)
{
    printf("Screen output required\n");
}
if (!(o & OUTPUT_BINARY))
{
    printf("La sortie binairie n'est pas requise");
}
```
]

---

# Les deux derniers types de base
## Le type `union`

En `C`, une `union` est un type de données défini par l'utilisateur qui permet de stocker différentes données dans le même espace mémoire. Contrairement aux structures (`struct`), où chaque membre a son propre espace mémoire, dans une union, tous les membres partagent le même espace mémoire. La taille de l'union est déterminée par la taille de son membre le plus grand.

.smaller[
.cols[
  .fifty[
```c
#include <stdio.h>
union Data {
    int i;
    float f;
    char str[20];
};
typedef union Data Data;

int main() {
    Data data;

    data.i = 10;
    printf("data.i: %d\n", data.i);

    data.f = 220.5;
    printf("data.f: %.2f\n", data.f);

    snprintf(data.str, sizeof(data.str), "Hello, World!");
    printf("data.str: %s\n", data.str);

    return 0;
}
```
]
.fifty[

Attention cependant, comme tous les membres partagent le même espace mémoire, modifier un membre affecte les autres. Il est donc important de savoir quel membre est actuellement actif pour éviter des comportements inattendus. Une bonne pratique est d'utiliser une énumération pour suivre quel type de donnée est actuellement stocké dans l'union et d'encapsuler cela dans une structure.

]
]
]

---

# Mise en pratique 

On va travailler sur la mise en place d'un mécanisme de pipeline de traitement de données simple. 

**Step 1** : Pour commencer vous devez implémenter 

```c

typedef struct {} Data;

Data abs_value(Data input){}
```

La difficulté est que dans Data je veux pouvoir gérer des scalair (valeur unique) ainsi que des tableau unidimensionnel. Et donc la fonction `abs_value` devra adapter son comportement suivant le type de données dans `input`. 

---

**Step 2** : définir une fonction `threashold` qui prend toujours un `Data input`en entrée mais maintenant ne fonctionne que sur des tableaux. Vous allez vite voir qu'il faut ce coup si passer un argument en plus, qui sera un `struct` contenant les paramètres du seuillage. 

```c
typedef struct { ... } ThreasholdParameters;

Data threashold(Data input, ThreasholdParameters parameters){}
```

**Step 3** : définir une interface unifiée pour toutes les fonctions du pipeline. 

```c
Data do_something(Data intput, void* parameters){}
``` 

**Step 4** : une fois l'API unifiée, définir un catalogue d'opération dans lequel on peu piocher le bon pointeur de fonction via un nom. 

**Step 5** : faire un pipeline linéaire "automatique" chainant différentes opérations. 


---

# Pour la prochaine séance

Voici ci-dessous un projet en `C` qui implémente une "hash map" (table de hachage) simple. Une table de hachage est une structure de données qui permet de stocker des paires clé-valeur et d'accéder rapidement aux valeurs en utilisant leurs clés, donc l'équivalent d'un dictionnaire en Python.

https://github.com/tidwall/hashmap.c/tree/master

Votre travail pour la semaine prochaine est d'étudier ce code, l'utiliser dans un petit programme de test. Vous devez étudier le code source, idéalement le comprendre, et préparer une question/remarque chacun.e. sur le code. 

Vous devez noter votre question/remarque [ici](https://docs.google.com/spreadsheets/d/1sdzgKsGwuicmW--fQvAGDa9jjUOhkhQA1I6qlnesdJk/edit?usp=sharing)

---

class: middle, center

# Séance 6 

## Utilisation de librairies externes

<a href="seance6"></a>

---

# Librairies externes 

Pour le moment nous avons vu comment développer tout ce dont on a besoin depuis **zéro** en `C`. Cela fonctionne et est formatteur pour des petits projets, mais on arrive vite à une taille critique où devoir réinventer la roue à chaque fois devient contre-productif. 
Heureusement pour nous il existe les librairies dont le principe est de pouvoir réutiliser des briques logiciels, que l'on a pas développées, dans nos projets. 

--

Des librairies il en existe pour tout et n'importe quoi 

- Interfaces graphiques 
- Algèbre linéaire 
- Calcul scientifique 
- Jeux vidéos 
- Traitement d'image 
- etc ... 

---

# Librairies externes 
## Deux grandes familles

Lorsqu’on utilise une bibliothèque externe, il existe deux grands modèles :


.cols[
  .fifty[

### Bibliothèques propriétaires
- code source fermé
- licence payante ou restrictive
- support assuré par un éditeur
- usage soumis à des conditions contractuelles
  ]
  .fifty[
### Bibliothèques open source
- code source accessible
- licence libre
- développement public
- maintenance communautaire ou institutionnelle
  ]
]

--

.cols[
  .sixty[
Une bibliothèque open source :
- peut être **lue**, **auditée** et **comprise**
- peut être **utilisée**, **modifiée** et **redistribuée** (selon la licence)
- évolue publiquement
- repose sur des standards ouverts

  ]
  .fourty[
⚠️ Open source ≠ absence de règles  
Les licences définissent précisément les droits et obligations.

  ]
]


---

# Librairies externes 
## Installations 

Alors là, ca ne va pas spécialement vous plaire. Contrairement à Python, qui a l'utilitaire `pip` (entre autres) pour gérer les dépendances, le `C` est un peu plus la jungle. Il n'y a pas de gestionnaire de dépendance officiel en `C`, ni en `C++` d'ailleurs. 

.center[Il existe différentes solutions, chacunes avec ses avantages et inconvénients.]

- Gestionnaires de paquets génériques des OS : 
  - `apt` sur debian/ubuntu 
  - `dnf`sur fedora/red hat 
  - `brew` sur macos 
- Gestionnaires de paquets spécifiques C/C++ 
  - `conan`
  - `vcpkg`
  - `spack` 

.center[La grosse difficulté c'est généralement de gérer l'arbre de dépendances]

---

# Librairies externes 
## Exemple fil rouge 

Pour cette séance, nous allons considérer un exemple fil rouge qui est l'utilisation de la [GSL](https://www.gnu.org/software/gsl/doc/html/index.html). Le librairie GSL pour (GNU Scientific Library) est une librairie C qui fournie tout un ensemble de fonctionnalité autour du calcul scientifique en `C`. 


.cols[
  .fifty[
```shell 
$ sudo apt install libgsl-dev
```
  ]
  .fifty[
```shell
$ brew install gsl 
```
  ]
]

**Attention** sous Linux on trouve très généralement les paquets `libXXX` et `libXXX-dev` si vous voulez développer des choses vous devez toujours utiliser la librairie `-dev` car elle seule contient les headers files. 


Après installation, sous Linux vous devez avoir : *
- le dossier des headers `/usr/include/gsl`
- les fichiers `/usr/lib/x86_64-linux-gnu/{libgsl.so, libgslcblas.so}`


---

# Librairies externes
## Notion d'**API**

L'utilisation de libairires externe fait apparaitre le besoin d'une API. 

.center[Application Programming Interface]

L'API c'est la porte d'entrée de la librairie. Pour utiliser une librairie on a pas envie de devoir savoir comment elle fonctionne en interne. C'est là où une API bien faite est importante car c'est notre point d'entrée. 


Une API C repose sur quelques principes simples :

- Structures opaques
- Allocation explicite
- Libération explicite
- Passage de pointeurs
- Gestion manuelle des erreurs

👉 Rien n’est caché.


---

# GSL 
## Premier exemple de base 

.cols[
  .sixty[
```c
#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_vector.h>

int main()
{

    gsl_vector *v = gsl_vector_alloc(3);

    gsl_vector_set(v, 0, 1.0);
    gsl_vector_set(v, 1, 2.0);
    gsl_vector_set(v, 2, 3.0);

    for (size_t i = 0; i < 3; i++)
    {
        printf("v[%zu] = %g\n", i, gsl_vector_get(v, i));
    }
    gsl_vector_free(v);
    return EXIT_SUCCESS;
}
```
  ]
  .fourty[
    A la compilation il faut faire deux choses particulières : 

    1. Dire où se trouve les headers de la GSL 
    2. Lier le programme à la librairie GSL. 

Sous Linux, une solution pour déterminer les options de compilation à passer est d'utiliser `pkg-config`

```shell
$ pkg-config --cflags --libs gsl
-lgsl -lgslcblas -lm 
```

  ]
]


---

# Mise en pratique 
## Système de N-ressorts 

**Objectif** : Déterminer le déplacement de $n$ ressorts en série sous l'effet d'une force.

**L'exercice** : 
Construisez la matrice de raideur globale $K$ par assemblage de matrices élémentaires, puis résolvez le système $Ku = f$ pour trouver les déplacements $u$.

💡 **Les Hints** :
- L'assemblage : Pensez bien à l'indice des nœuds. Un ressort $i$ relie les nœuds $i$ et $i+1$. Sa contribution doit être ajoutée (et non remplacée) dans la matrice globale.
- Conditions aux limites : Le premier nœud est fixe ($u_0 = 0$). Pour "bloquer" ce nœud dans votre système, une astuce simple consiste à imposer en 0,0 un gros terme 1.e20. 
- Résolution : Utilisez gsl_linalg_LU_solve. Attention, cette fonction modifie souvent la matrice d'origine !

---

# Mise en pratique 
## Intégrateur RK4 sur Lotka-Volterra 

**Objectif** : Simuler l'évolution de deux populations sur le temps long.

**L'exercice** : Implémentez le schéma de Runge-Kutta 4 (RK4) pour résoudre le système différentiel de Lotka-Volterra.

**💡 Les Hints** :
- RK4 "à la main" : L'usage des intégrateurs automatiques de la GSL est interdit ici. Vous devez coder les 4 étapes ($k_1, k_2, k_3, k_4$) en utilisant les fonctions de manipulation de vecteurs gsl_vector.
- Optimisation mémoire : C'est le point critique. Interdiction totale d'allouer ou de libérer de la mémoire dans votre boucle temporelle. Créez vos vecteurs de travail avant la boucle et réutilisez-les.
- Modularité : Séparez bien la fonction qui calcule les dérivées (le modèle) de la fonction qui calcule un pas de temps (l'algorithme).



---

class: middle, center

# Séance 7

## Tester et debugger 

<a href="seance7"></a>


---

# Tester 
## Tester c'est douter 

Un adage classique en programmation est de dire que 

.center[Tester c'est douter]

Je dirais personnellement que le doute est une chose saine !! 

Plus sérieusement, pour du code un tout petit peu sérieux il est indispensable de mettre en place une base de test unitaire. 

- Une fonction C = une boîte noire

- Un test =

  - des entrées connues
  - un résultat attendu
  - une assertion


---

# Tester 
## Sans framework 

Pour faire une base de test simple, une solution artisanale consiste à utiliser des assert. 

.cols[
  .sixty[
```c
#include <assert.h>
#include <math.h>

double norm2(double x, double y) {
    return sqrt(x*x + y*y);
}

void test_norm2() {
    assert(fabs(norm2(3.0, 4.0) - 5.0) < 1e-12);
    assert(norm2(0.0, 0.0) == 0.0);
}

int main(void) {
    test_norm2();
    return 0;
}
```
  ]
  .fourty[
L'intérêt du assert est qu'n cas d'erreur 
- on saura quelle assertion échoue 
- le programme interrompra son exécution

  ]
]

---

# Tester 
## Framework plus lourd 

Il existe plein de framework pour mettre en place des tests unitaires 

| Framework | Dépendances | Simplicité | Mocks | Industrie |
| --------- | ----------- | ---------- | ----- | --------- |
| assert.h  | aucune      | ⭐⭐⭐⭐⭐      | ❌     | ⚠️        |
| Unity     | très faible | ⭐⭐⭐⭐       | ⚠️    | ⭐⭐        |
| cmocka    | faible      | ⭐⭐⭐        | ✅     | ⭐⭐⭐⭐      |
| Check     | moyenne     | ⭐⭐         | ⚠️    | ⭐⭐⭐       |
| Criterion | élevée      | ⭐⭐         | ✅     | ⭐⭐⭐⭐      |

Inutile de se prendre trop la tête avec ça pour le moment. Pour vos besoins, `assert` fait parfaitement le job ;)

---
# Tester 
## Bonnes pratiques 

Pour que les tests soient efficace il faut : 

- Tester les cas limites

- Tester les erreurs

- Tester avant d’optimiser

- Ne pas tester printf, tester les valeurs

---

# Debug
## `printf` n'est pas une solution 

Pour debuger un programme, faire des printf dans tous les sens n'est pas une solution viable. 

La seule solution que vous devez envisager est d'utiliser un debuggeur ! 

- GDB sous Linux 
- LLDB sous MacOS

Le debuggeur est un programme externe, qui va s'occuper de gérer l'exécution de votre programme et vous permettre de l'inspecter pendant son exécution. Afin de permettre au debuggeur d'avoir la main sur votre exécutable il est nécessaire lors de sa compilation que vous activiez une option 

```shell
$ gcc -g -O0  main.c
```

Cela va générer un binaire **plus lent** mais debugable ! 

---

# Debug 
## Les commandes à connaitre 

```bash
gdb ./a.out
run                   #-> Lance l'exécution du programme 
print x               #-> Affiche la variable x 
break fichier.c:YY    #-> Met un breakpoint ligne YY de fichier.c 
break functionName    #-> Met un breakpoint à l'entrée de functionName
next                  #-> Passe à la ligne suivant 
step                  #-> Rentre dans la ligne
where                 #-> Situe la position courante dans le flux d'exécution 
```

---

# Debug 
## Trouver les fuites mémoires 

GDB/LLDB permettent de trouver les segfault et identifier les comportements non-désirés dans les programmes. Il reste cependant un type de "bug" à gérer, les **fuites mémoires**. 

Pour rappel, une fuite mémoire correspond à une mauvaise gestion de la mémoire. Concrètement c'est un `malloc` auquel aucun `free` n'est associé. En pratique ce n'est pas critique, jusqu'au moment où votre RAM explose 💣. 

Il est donc indispensable d'intégrer dans le process de développement des outils de contrôle. Notamment un outil de détection de fuites mémoire est `AddressSanitizer` qui est intégré dans les compilateurs moderne. Le principe est que cela va instrumenter votre code et ainsi permettre de détecter toutes corruption ou mauvais usage de la mémoire. 

**Attention**, comme pour le mode debug cela génère des exécutables plus lent !

---

# Debug 
## AddressSanitizer 

Pour activer l'adresse sanitizer il suffit de mettre l'option de compilation comme ci-dessous 

```bash 
$ gcc main.c -fsanitize=address 
```
.smaller[
.cols[
  .fifty[
```c
#include <stdlib.h>

void foo()
{
    int *leak = (int *)malloc(sizeof(int) * 10);
    if (leak == NULL)
    {
        return;
    }
    leak[0] = 42;
}

int main(void)
{
    foo();
    return 0;
}
```
  ]
  .fifty[
```bash
$ gcc -fsanitize=address main.c
$ ./a.out 
=================================================================
==798903==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 40 byte(s) in 1 object(s) allocated from:
    #0 0x750f17afd9c7 in malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:69
*   #1 0x5fac2b8201be in foo /home/bmarchand/enseignements/mines_cic/layout/demo_asan.c:5
*   #2 0x5fac2b820221 in main /home/bmarchand/enseignements/mines_cic/layout/demo_asan.c:15
    #3 0x750f1762a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #4 0x750f1762a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #5 0x5fac2b8200e4 in _start (/home/bmarchand/enseignements/mines_cic/layout/a.out+0x10e4) (BuildId: 092613a6f076ba975d98a8ca291603b266a5abbe)

SUMMARY: AddressSanitizer: 40 byte(s) leaked in 1 allocation(s).
```
  ]
]
]

---

# Optimisation 
## Trouver les hot spots 

Pour finir, quand on a un programme qui fonctionne et sans fuite mémoire, on peut chercher à optimiser les choses. Pour cela, pas de magie, il faut identifier les parties qui prennent du temps dans le code. Pour cela il existe plein d'outils de profiling. Un outil simple est d'activer l'option `-pg` à la compilation. 

.smaller[
.cols[
  .fifty[
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double heavy_compute(int n){
    double s = 0.0;
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
          s += (i * 0.5) / (j + 1.0);
      }
    }
    return s;
}
void process(int n, int repeat){
    double result = 0.0;
    for (int i = 0; i < repeat; ++i){
      result += heavy_compute(n);
    }
}
int main(void)
{
    process(800, 10);
    return 0;
}
```    
  ]
  .fifty[
```bash 
$ gcc -pg demo_perf.c   
$ ./a.out 
$ gprof ./a.out gmon.out 
Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
100.00      0.04     0.04       10     4.00     4.00  heavy_compute
  0.00      0.04     0.00        1     0.00    40.00  process
```
  ]
]
]


---

# Mise en pratique 

Tout est là 

.center[https://github.com/ue12-p25/c-debug-optim]

.center[

<iframe src="https://giphy.com/embed/lY1F6BJjbRO3m" width="480" height="331" style="" frameBorder="0" class="giphy-embed" allowFullScreen></iframe>
]

---

class: center, middle 

[https://github.com/ue12-p25/c-space-invaders-starter](https://github.com/ue12-p25/c-space-invaders-starter)

---
