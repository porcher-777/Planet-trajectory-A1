#include "init.h"

//*************** Initialisation de chaque planète (même les 4 planètes gazeuses) + la Lune ****************

planete initplaneteMercure(){
    planete mercure;
    mercure.masse = 3.285 * pow(10, 23);
    mercure.perihelie = 4.7 * pow(10, 10); //en mètre
    strcpy(mercure.nom_planete, "Mercure");
    mercure.vitessePerihelie = 58975; //en mètre par secondes
    mercure.pas = 8640;

    return mercure;
}

planete initplaneteTerre(){

    planete terre;
    terre.masse = 5.972 * pow (10, 24);
    terre.perihelie = 1.47 * pow (10, 11); //en mètre
    strcpy(terre.nom_planete, "Terre");
    terre.vitessePerihelie = 30287; //en mètre par secondes
    terre.pas = 8640;

    return terre;
}

planete initplaneteMars(){

    planete mars;
    mars.masse = 6.39 * pow (10, 23);
    mars.perihelie = 2.06 * pow (10, 11); //en mètre
    strcpy(mars.nom_planete, "Mars");
    mars.vitessePerihelie = 26503; //en mètre par secondes
    mars.pas = 8640;

    return mars;
}

planete initplaneteVenus(){

    planete venus;
    venus.masse = 4.867 * pow (10, 24);
    venus.perihelie = 1.07 * pow (10, 11); //en mètre
    strcpy(venus.nom_planete, "Venus");
    venus.vitessePerihelie = 35264; //en mètre par secondes
    venus.pas = 8640;

    return venus;
}

planete initHalley(){
    planete halley;
    halley.masse = 2.2 * pow (10, 44);
    halley.perihelie = 8.78 * pow (10, 10); //en mètre
    strcpy(halley.nom_planete, "Halley");
    halley.vitessePerihelie = -54500; //en mètre par secondes
    halley.pas = 200000;

    return halley;
}

planete initplaneteJupiter(){

    planete Jupiter;
    Jupiter.masse = 1.898 * pow (10, 27);
    Jupiter.perihelie = 7.4 * pow (10, 11); //en mètre
    strcpy(Jupiter.nom_planete, "Jupiter");
    Jupiter.vitessePerihelie = 13714; //en mètre par secondes
    Jupiter.pas = 8640;

    return Jupiter;
}

planete initplaneteSaturne(){

    planete Saturne;
    Saturne.masse = 5.683 * pow (10, 26);
    Saturne.perihelie = 1.349 * pow (10, 12); //en mètre
    strcpy(Saturne.nom_planete, "Saturne");
    Saturne.vitessePerihelie = 10182; //en mètre par secondes
    Saturne.pas = 8640;

    return Saturne;
}

planete initplaneteUranus(){

    planete Uranus;
    Uranus.masse = 8.681 * pow (10, 25);
    Uranus.perihelie = 2.734 * pow (10, 12); //en mètre
    strcpy(Uranus.nom_planete, "Uranus");
    Uranus.vitessePerihelie = 7129; //en mètre par secondes
    Uranus.pas = 8640;

    return Uranus;
}

planete initplaneteNeptune(){

    planete Neptune;
    Neptune.masse = 1.024 * pow (10, 26);
    Neptune.perihelie = 4.459 * pow (10, 12); //en mètre
    strcpy(Neptune.nom_planete, "Neptune");
    Neptune.vitessePerihelie = 5479; //en mètre par secondes
    Neptune.pas = 8640;

    return Neptune;
}

planete initLune(){
    planete Lune;
    Lune.masse = 7.6 * pow (10, 22);
    Lune.perihelie = 3.565 * pow (10, 8); //en mètre
    strcpy(Lune.nom_planete, "Lune");
    Lune.vitessePerihelie = 3590; //en mètre par secondes
    Lune.pas = 8720;

    return Lune;
}

planete* initPlanete(int nb_planete){
    if(nb_planete > 8){
        return EXIT_FAILURE;
    }

    planete* tabPlanete = malloc(8 * sizeof(planete));
    tabPlanete[0] = initplaneteMercure();
    tabPlanete[1] = initplaneteVenus();
    tabPlanete[2] = initplaneteTerre();
    tabPlanete[3] = initplaneteMars();
    tabPlanete[4] = initplaneteJupiter();
    tabPlanete[5] = initplaneteSaturne();
    tabPlanete[6] = initplaneteUranus();
    tabPlanete[7] = initplaneteNeptune();

    planete* tabPlaneteChoisie = malloc(nb_planete * sizeof(planete));

    for(int i = 0; i < nb_planete; i++){
        tabPlaneteChoisie[i] = tabPlanete[i];
    }

    free(tabPlanete);

    return tabPlaneteChoisie;
}

//*************** Initialisation de chaque planète à la périhélie + la Lune à la périgée ****************

point init(planete astre){
    point p;

    p.r.x = astre.perihelie;
    p.r.y = 0;
    p.r.z = 0;

    p.v.x = 0;
    p.v.y = astre.vitessePerihelie;
    p.v.z = 0;

    p.temps = 0;

    return p;
}
