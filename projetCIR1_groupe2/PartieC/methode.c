#include "methode.h"

vector CalculerAcceleration(vector Vect) {
    return CalculerMulVecteur(Vect, (-G * MS) / pow(CalculerNormeVecteur(Vect), 3));
}

vector CalculerAccelerationLune(vector Vect){
    return CalculerMulVecteur(Vect, (-G * MT) / pow(CalculerNormeVecteur(Vect), 3));
}

vector CalculerPosition_VitesseEuler(vector Vect1, vector Vect2, float pas) {
    return CalculerAddVecteur(Vect1, CalculerMulVecteur(Vect2, pas));
}

trajectoire CalculerHalley(FILE* fichier, trajectoire trajectoire, vector acc, int nb_positions){
    planete Halley = initHalley();
    point ptHalley = init(Halley);
    trajectoire.tab_trajectoire = malloc(nb_positions * sizeof(point));
    MethodeKR2(trajectoire, ptHalley, Halley, nb_positions);
    strcpy(trajectoire.nom_methode, strcat(Halley.nom_planete, "EulerAsymetrique"));

    for (int j = 0; j < nb_positions; j++) {
        ptHalley.r = CalculerPosition_VitesseEuler(ptHalley.r, ptHalley.v, Halley.pas);
        acc = CalculerAcceleration(ptHalley.r);
        ptHalley.v = CalculerPosition_VitesseEuler(ptHalley.v, acc, Halley.pas);
        ptHalley.temps = j;
        trajectoire.tab_trajectoire[j] = ptHalley;

        printf("[[%e, %e, %e],[%e, %e, %e]], %d]\t %e\n", ptHalley.r.x, ptHalley.r.y, ptHalley.r.z, ptHalley.v.x, ptHalley.v.y, ptHalley.v.z, ptHalley.temps);
    }

    fprintf(fichier, "{\"%s\" : [\n", trajectoire.nom_methode);
    for (int i = 0; i < nb_positions - 1; i++){
        fprintf(fichier, "[[%e, %e, %e],[%e, %e, %e], %d],\n", trajectoire.tab_trajectoire[i].r.x, trajectoire.tab_trajectoire[i].r.y, trajectoire.tab_trajectoire[i].r.z, trajectoire.tab_trajectoire[i].v.x, trajectoire.tab_trajectoire[i].v.y, trajectoire.tab_trajectoire[i].v.z, trajectoire.tab_trajectoire[i].temps);
    }
    fprintf(fichier, "[[%e, %e, %e],[%e, %e, %e], %d]],\n", trajectoire.tab_trajectoire[nb_positions - 1].r.x, trajectoire.tab_trajectoire[nb_positions - 1].r.y, trajectoire.tab_trajectoire[nb_positions - 1].r.z, trajectoire.tab_trajectoire[nb_positions - 1].v.x, trajectoire.tab_trajectoire[nb_positions - 1].v.y, trajectoire.tab_trajectoire[nb_positions - 1].v.z, trajectoire.tab_trajectoire[nb_positions - 1].temps);

    free(trajectoire.tab_trajectoire);
}

//Calcul de l'énergie totale pour vérifier sir le pas est correct
double CalculerEtot(planete astre, point p){
    double Ep = (G * MS * astre.masse) / pow(CalculerNormeVecteur(p.r), 2);
    double Ec = 0.5 * astre.masse * pow(CalculerNormeVecteur(p.v), 2);
    return Ep + Ec;
}

//3 méthodes de calcul de la trajectoire

trajectoire MethodeEuler(trajectoire traj, point pt, vector acc, planete astre, int nb_positions){
    for (int i = 0; i < nb_positions; i++) {
        acc = CalculerAcceleration(pt.r);
        pt.r = CalculerPosition_VitesseEuler(pt.r, pt.v, astre.pas);
        pt.v = CalculerPosition_VitesseEuler(pt.v, acc, astre.pas);
        pt.temps = i;
        traj.tab_trajectoire[i] = pt;

        printf("[[%e, %e, %e],[%e, %e, %e]], %d]\t %e\n", pt.r.x, pt.r.y, pt.r.z, pt.v.x, pt.v.y, pt.v.z, pt.temps, CalculerEtot(astre, pt));
    }
    return traj;
}

trajectoire MethodeEulerAsymetrique(trajectoire traj, point pt, vector acc, planete astre, int nb_positions){
    for (int i = 0; i < nb_positions; i++) {
        pt.r = CalculerPosition_VitesseEuler(pt.r, pt.v, astre.pas);
        acc = CalculerAcceleration(pt.r);
        pt.v = CalculerPosition_VitesseEuler(pt.v, acc, astre.pas);
        pt.temps = i;
        traj.tab_trajectoire[i] = pt;

        printf("[[%e, %e, %e],[%e, %e, %e]], %d]\t %e\n", pt.r.x, pt.r.y, pt.r.z, pt.v.x, pt.v.y, pt.v.z, pt.temps, CalculerEtot(astre, pt));
    }
    return traj;
}

trajectoire MethodeKR2(trajectoire traj, point pt, planete astre, int nb_positions){
    point K1, K2 = {0,0,0};
    for (int i = 0; i < nb_positions; i++) {

        K1.r = CalculerMulVecteur(pt.v, astre.pas);
        K1.v = CalculerMulVecteur(pt.r, astre.pas * (-G * MS) / pow(CalculerNormeVecteur(pt.r), 3));

        K2.r = CalculerMulVecteur(CalculerAddVecteur(pt.v, CalculerMulVecteur(K1.v, 0.5)), astre.pas);
        K2.v = CalculerMulVecteur(CalculerAddVecteur(pt.r, CalculerMulVecteur(K1.r, 0.5)), astre.pas * (-G * MS) / pow(CalculerNormeVecteur(CalculerAddVecteur(pt.r, CalculerMulVecteur(K1.r, 0.5))), 3));

        pt.r = CalculerAddVecteur(pt.r,K2.r);
        pt.v = CalculerAddVecteur(pt.v,K2.v);

        pt.temps = i;
        traj.tab_trajectoire[i] = pt;
        printf("[[%e, %e, %e],[%e, %e, %e]], %d]\t %e\n", pt.r.x, pt.r.y, pt.r.z, pt.v.x, pt.v.y, pt.v.z, pt.temps, CalculerEtot(astre, pt));
    }
}

//Fonction permettant de créer le JSON : plusieurs cas possibles selon le nombre de planète

void RemplirFichier(FILE* fichier, trajectoire astre, int nb_iteration, int nb_planete, int j){
    if (fichier == NULL){
        printf("LE FICHIER NE S'OUVRE PAS\n");
    }

    if(j == 0 && nb_planete > 3){   //Dans le cas de la Lune
        fprintf(fichier, "\"%s\" : [\n", astre.nom_methode);
        for (int i = 0; i < nb_iteration - 1; i++){
            fprintf(fichier, "[[%e, %e, %e],[%e, %e, %e], %d],\n", astre.tab_trajectoire[i].r.x, astre.tab_trajectoire[i].r.y, astre.tab_trajectoire[i].r.z, astre.tab_trajectoire[i].v.x, astre.tab_trajectoire[i].v.y, astre.tab_trajectoire[i].v.z, astre.tab_trajectoire[i].temps);
        }
        fprintf(fichier, "[[%e, %e, %e],[%e, %e, %e], %d]\n],\n", astre.tab_trajectoire[nb_iteration - 1].r.x, astre.tab_trajectoire[nb_iteration - 1].r.y, astre.tab_trajectoire[nb_iteration - 1].r.z, astre.tab_trajectoire[nb_iteration - 1].v.x, astre.tab_trajectoire[nb_iteration - 1].v.y, astre.tab_trajectoire[nb_iteration - 1].v.z, astre.tab_trajectoire[nb_iteration - 1].temps);
    }

    if(nb_planete == 1){    //Dans le cas où il n'y a qu'une seule planète
        fprintf(fichier, "{\"%s\" : [\n", astre.nom_methode);
        for (int i = 0; i < nb_iteration - 1; i++){
            fprintf(fichier, "[[%e, %e, %e],[%e, %e, %e], %d],\n", astre.tab_trajectoire[i].r.x, astre.tab_trajectoire[i].r.y, astre.tab_trajectoire[i].r.z, astre.tab_trajectoire[i].v.x, astre.tab_trajectoire[i].v.y, astre.tab_trajectoire[i].v.z, astre.tab_trajectoire[i].temps);
        }
        fprintf(fichier, "[[%e, %e, %e],[%e, %e, %e], %d]\n]}\n", astre.tab_trajectoire[nb_iteration - 1].r.x, astre.tab_trajectoire[nb_iteration - 1].r.y, astre.tab_trajectoire[nb_iteration - 1].r.z, astre.tab_trajectoire[nb_iteration - 1].v.x, astre.tab_trajectoire[nb_iteration - 1].v.y, astre.tab_trajectoire[nb_iteration - 1].v.z, astre.tab_trajectoire[nb_iteration - 1].temps);
    }

    else if( j > 0 && j < nb_planete - 1){  //Dans le cas de plusieurs planètes
        fprintf(fichier, "\"%s\" : [\n", astre.nom_methode);
        for (int i = 0; i < nb_iteration - 1; i++){
            fprintf(fichier, "[[%e, %e, %e],[%e, %e, %e], %d],\n", astre.tab_trajectoire[i].r.x, astre.tab_trajectoire[i].r.y, astre.tab_trajectoire[i].r.z, astre.tab_trajectoire[i].v.x, astre.tab_trajectoire[i].v.y, astre.tab_trajectoire[i].v.z, astre.tab_trajectoire[i].temps);
        }
        fprintf(fichier, "[[%e, %e, %e],[%e, %e, %e], %d]\n],\n", astre.tab_trajectoire[nb_iteration - 1].r.x, astre.tab_trajectoire[nb_iteration - 1].r.y, astre.tab_trajectoire[nb_iteration - 1].r.z, astre.tab_trajectoire[nb_iteration - 1].v.x, astre.tab_trajectoire[nb_iteration - 1].v.y, astre.tab_trajectoire[nb_iteration - 1].v.z, astre.tab_trajectoire[nb_iteration - 1].temps);
    }


    else if (j == nb_planete - 1){  //Dans le cas d'une fin de fichier, dernière planète rentrée
        fprintf(fichier, "\"%s\" : [\n", astre.nom_methode);
        for (int i = 0; i < nb_iteration - 1; i++){
            fprintf(fichier, "[[%e, %e, %e],[%e, %e, %e], %d],\n", astre.tab_trajectoire[i].r.x, astre.tab_trajectoire[i].r.y, astre.tab_trajectoire[i].r.z, astre.tab_trajectoire[i].v.x, astre.tab_trajectoire[i].v.y, astre.tab_trajectoire[i].v.z, astre.tab_trajectoire[i].temps);
        }
        fprintf(fichier, "[[%e, %e, %e],[%e, %e, %e], %d]\n]}", astre.tab_trajectoire[nb_iteration - 1].r.x, astre.tab_trajectoire[nb_iteration - 1].r.y, astre.tab_trajectoire[nb_iteration - 1].r.z, astre.tab_trajectoire[nb_iteration - 1].v.x, astre.tab_trajectoire[nb_iteration - 1].v.y, astre.tab_trajectoire[nb_iteration - 1].v.z, astre.tab_trajectoire[nb_iteration - 1].temps);
    }
}