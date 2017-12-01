# Numkinch

Projet de Programmation Orientée Objet Avancée, dans le cadre d'un semestre académique en informatique à l'UQAC.

## Description

Numkinch est un jeu de rôle / jeu de cartes 2D multi-joueurs en local s'inspirant vaguement du jeu de société Munchkin créé par Steve Jackson.

### Règles

À chaque tour blablabla.

## Équipe

Chloé Belguermi & Damien Haurat.

### Processus de développement

#### Spécifications

Nous avons rédigé les scénarios / cas d'utilisation du programme en amont du développement.

Les scénarios sont disponibles dans le dossier `doc`.

#### Développement

Nous avons travaillé en ***pair-programming*** avec l'IDE CLion, sous environnements Linux et Mac.

#### Documentation

Doxygen

Le diagramme de classes est disponible dans le dossier `doc`.

## Compilation des sources

Le programme utilise la bibliothèque graphique SDL.

### Installation de la SDL

#### Sous macOS

Télécharger les images-disques de `SDL2`, `SDL2_image` et `SDL2_ttf` aux adresses suivantes :

https://www.libsdl.org/download-2.0.php
https://www.libsdl.org/projects/SDL_image/
https://www.libsdl.org/projects/SDL_ttf/

Ces images-disques contiennent chacune un fichier `.framework` qu'il suffit de déplacer dans le dossier `/Library/Frameworks`.

#### Sous Linux Ubuntu

Installer les paquetages `SDL2`, `SDL2_image` et `SDL2_ttf` suivants :

`sudo apt install libsdl2-dev`

`sudo apt install libsdl2-image-dev`

`sudo apt install libsdl2-ttf-dev`

(attention à bien choisir la version finissant par `dev`)

### Construction du projet

`CMake` est utilisé.

Génère un `Makefile`.

À la racine du projet, lancer la commande `make`. Un exécutable nommé `Numkinch` sera généré.