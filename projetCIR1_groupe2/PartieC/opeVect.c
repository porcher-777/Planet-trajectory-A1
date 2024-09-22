#include "opeVect.h"

vector CalculerAddVecteur(vector Vect1, vector Vect2){
    vector vecteurAdd;
    vecteurAdd.x = Vect1.x + Vect2.x;
    vecteurAdd.y = Vect1.y + Vect2.y;
    vecteurAdd.z = Vect1.z + Vect2.z;

    return vecteurAdd;
}

vector CalculerSubVecteur(vector Vect1, vector Vect2){
    vector vecteurSub;
    vecteurSub.x = Vect1.x - Vect2.x;
    vecteurSub.y = Vect1.y - Vect2.y;
    vecteurSub.z = Vect1.z - Vect2.z;

    return vecteurSub;
}

vector CalculerMulVecteur(vector Vect1, float scalaire){
    vector vecteurMul;
    vecteurMul.x = Vect1.x * scalaire;
    vecteurMul.y = Vect1.y * scalaire;
    vecteurMul.z = Vect1.z * scalaire;

    return vecteurMul;
}

float CalculerNormeVecteur(vector Vect){
    return sqrt(pow(Vect.x, 2) + pow(Vect.y, 2) + pow(Vect.z, 2));
}
