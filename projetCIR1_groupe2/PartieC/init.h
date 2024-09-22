#ifndef PROJETCIR1_GROUPE2_INIT_H
#define PROJETCIR1_GROUPE2_INIT_H

#include "opeVect.h"


typedef struct s_Point{
    vector r;   //position
    vector v;   //vitesse
    int temps;
} point;

typedef struct s_planete{
    char nom_planete[25];
    float masse;
    float perihelie;
    float vitessePerihelie;
    float pas;
} planete;

planete initplaneteMercure();
planete initplaneteTerre();
planete initplaneteMars();
planete initplaneteVenus();
planete initHalley();

planete initplaneteJupiter();
planete initplaneteSaturne();
planete initplaneteUranus();
planete initplaneteNeptune();

planete initLune();

planete* initPlanete(int nb_planete);
point init(planete astre);

#endif //PROJETCIR1_GROUPE2_INIT_H
