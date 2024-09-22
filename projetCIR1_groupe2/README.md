# Projet C et Web : trajectoire de planète

## Description du Projet
    Le but premier du fichier est de générer, à l'aide du langage C, un fichier JSON contenant les positions et vitesses d'une plaète à un instant t puis de lire ce fichier grâce à la bibliothèque "p5.js".
    Ici, il est possible d'afficher 4 planètes : Mercure, Vénus, la Terre et la comète de Halley grâce au javascript ainsi que Mercure uniquement avec la SDL2.

## Comment tester le projet    
    Le test du projet commence par l'exécution du C, 2 choix sont possibles :
        - La variable "nb_planete" est initialisée à 4 par défaut, dans ce cas exécuter le programme, 2 choses vous sont demandées : le nombre de points 
        (à savoir qu'il faut un minimum de 12640 points pour que la comète de Halley effectue une révolution complète) à calculer ainsi que la méthode de calcul utilisée (Euler = 0, Euler asymétrique = 1 ou Runge Kutta 2 = 2).
        Un fichier JSON "Planete.json" est créé sous la forme suivante : 
{"HalleyEulerAsymetrique" : [
  [[8.780000e+10, -1.090000e+10, 0.000000e+00],[-3.365919e+03, -5.408214e+04, 0.000000e+00], 0]],  
  "MercureEuler" : [
  [[4.700000e+10, 5.095440e+08, 0.000000e+00],[-5.192114e+02, 5.897500e+04, 0.000000e+00], 0]
  ],  
  "VenusEuler" : [
  [[1.070000e+11, 3.046810e+08, 0.000000e+00],[-1.001780e+02, 3.526400e+04, 0.000000e+00], 0]
  ],  
  "TerreEuler" : [
  [[1.470000e+11, 2.616797e+08, 0.000000e+00],[-5.307686e+01, 3.028700e+04, 0.000000e+00], 0]
  ],  
  "MarsEuler" : [
  [[2.060000e+11, 2.289859e+08, 0.000000e+00],[-2.702748e+01, 2.650300e+04, 0.000000e+00], 0]
  ]}  

        Lorsque le C a fini de s'exécuter, lancer la page "index.html". 
        Cliquer sur le bouton correspondant à la méthode de calcul choisie durant l'exécution puis sur le bouton "Choose a file" : sélectionner le fichier "Planete.json" et admirer !

        - Mettre la variable "nb_planete" à 1 et décommenté la ligne 43 : "dessin(fichier, trajectoire, nb_positions);".
        Si vous utilisez une machine distante (wsl2), allez dans Edit Configurations (sur CLion) -> Environment variables : DISPLAY = <l'adresse IP de votre machine distante>:0.
        Lancer Xming ou un logiciel similaire et admirer ! 

## Outils utilisés (pour l'affichage graphique)
    - Bibliothèque "p5.js" (gratuit et open source) : https://cdn.jsdelivr.net/npm/p5@1.4.1/lib/p5.js
    - Bibliothèque SDL2 : sudo apt-get install libsdl2-dev (commande Debian)    #include <SDL2/SDL.h> pour l'appel dans le code C
    - L'intégralité des tests web ont été réalisés sur Opera
    - Les tests de l'affichage avec la SDL ont été réalisés avec Xming



