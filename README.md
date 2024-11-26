 MARC Rover Simulation

## Description
Le projet **MARC Rover Simulation** est un programme permettant de simuler les déplacements d'un rover (MARC) sur une carte, en trouvant des chemins optimaux et en évitant les obstacles. L'objectif est de guider le rover jusqu'à une station de base tout en optimisant ses mouvements.

## Fonctionnalités
- Lecture et gestion des cartes de différentes tailles.
- Génération de mouvements optimaux grâce à un arbre de décisions.
- Visualisation de la progression du rover sur la carte.
- Analyse des performances en temps réel, avec mesure des temps de calcul pour chaque phase.

## Structure du Projet
- `main.c` : Point d'entrée principal du programme.
- `map.c/h` : Gestion des cartes (chargement, affichage, validation).
- `moves.c/h` : Gestion des mouvements possibles pour le rover.
- `tree.c/h` : Construction et manipulation de l'arbre de décision.
- `simulation.c/h` : Simulation principale des déplacements et interactions.
- `performance.c/h` : Chronométrage et analyse des performances.
- `visualization.c/h` : Visualisation de la carte et des déplacements.
- `maps-backup/` : Contient des fichiers de cartes exemples.

## Prérequis
- Un environnement de développement C (compilateur GCC ou Clang recommandé).
- `CMake` pour la gestion de la construction.

## Installation
1. Clonez le dépôt :
   ```bash
   git clone https://github.com/votre-utilisateur/marc-rover-simulation.git
   cd marc-rover-simulation
## Compilation et Exécution

### Compilez le projet avec CMake :
``` bash
mkdir build
cd build
cmake ..
make
```
## Exécuter le programme : 

```
./MARC_Rover
```
## Utilisation

Lors de l'exécution, vous serez invité à effectuer les actions suivantes :
1. Fournir un fichier de carte existant (ex. `example1.map` ou `test_slope.map`).
2. Générer une carte aléatoire en précisant ses dimensions.

Suivez la simulation affichée dans la console :
- Les déplacements du rover sont décrits à chaque étape.
- La carte est visualisée après chaque mouvement.

À la fin, le programme affiche :
- Le chemin parcouru.
- Les coûts associés à chaque déplacement.
- Le temps total de simulation et les performances mesurées.

## Exemples de cartes

Les fichiers de cartes sont situés dans le dossier `maps-backup/`.

## Lien du dépôt
   ```bash
   https://github.com/Aminecsh/Projet-MARC-Rover
