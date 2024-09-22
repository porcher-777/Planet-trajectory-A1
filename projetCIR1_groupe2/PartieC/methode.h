#ifndef PROJETCIR1_GROUPE2_METHODE_H
#define PROJETCIR1_GROUPE2_METHODE_H

#include "init.h"
#include "opeVect.h"

typedef struct s_Trajectoire{
    char nom_methode[25];
    point* tab_trajectoire;
} trajectoire;

vector CalculerAcceleration(vector Vect);
vector CalculerAccelerationLune(vector Vect);
vector CalculerPosition_VitesseEuler(vector Vect1, vector Vect2, float pas);

trajectoire CalculerLune(FILE* fichier, trajectoire trajectoire, vector acc, int nb_positions);
trajectoire CalculerHalley(FILE* fichier, trajectoire trajectoire, vector acc, int nb_positions);

double CalculerEtot(planete astre, point p);

trajectoire MethodeEuler(trajectoire traj, point pt, vector acc, planete astre, int nb_positions);
trajectoire MethodeEulerAsymetrique(trajectoire traj, point pt, vector acc, planete astre, int nb_positions);
trajectoire MethodeKR2(trajectoire traj, point pt, planete astre, int nb_positions);

void RemplirFichier(FILE* fichier, trajectoire astre, int nb_iteration, int nb_planete, int iteration);
#endif
