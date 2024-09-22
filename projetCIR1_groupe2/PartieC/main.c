#include "methode.h"
#include "dessin_SDL.h"

int main() {
    FILE* fichier;
    int nb_positions = 0, methode = 0;
    int nb_planete = 4;     // Paramètre à mettre à 1 pour tester la modélisation de la trajectoire de Mercure avec la SDL2

    printf("Combien de position souhaitez-vous calculer ? > ");
    scanf("%d", &nb_positions);
    /*printf("Combien de planètes souhaitez-vous inclure (entre 1 et 8)? > ");
    scanf("%d", &nb_planete);*/
    printf("Quelle méthode souhaitez-vous utiliser (0 pour Euler, 1 pour Euler asymétrique ou 2 pour Kunge Rutta d'ordre 2) ? > ");
    scanf("%d", &methode);
    vector acc = {0,0,0};

    trajectoire trajectoire;
    planete* tabPlanete = initPlanete(nb_planete);
    fichier = fopen("Planete.json", "w+");

    CalculerHalley(fichier, trajectoire, acc, nb_positions);

    for(int j = 0; j < nb_planete; j++){
        trajectoire.tab_trajectoire = malloc(nb_positions * sizeof(point));
        planete astre = tabPlanete[j];
        point pt = init(astre);

        switch(methode) {
            case 0:
                MethodeEuler(trajectoire, pt, acc, astre, nb_positions);
                strcpy(trajectoire.nom_methode, strcat(astre.nom_planete, "Euler"));
                break;
            case 1:
                MethodeEulerAsymetrique(trajectoire, pt, acc, astre, nb_positions);
                strcpy(trajectoire.nom_methode, strcat(astre.nom_planete, "EulerAsymetrique"));
                break;
            case 2:
                MethodeKR2(trajectoire, pt, astre, nb_positions);
                strcpy(trajectoire.nom_methode, strcat(astre.nom_planete, "RK2"));
                break;
        }
        RemplirFichier(fichier, trajectoire, nb_positions, nb_planete, j);
        dessin(fichier, trajectoire, nb_positions);   //Fonctionne uniquement avec une planète -> Mercure
        free(trajectoire.tab_trajectoire);
    }
    fclose(fichier);

    return 0;
}
