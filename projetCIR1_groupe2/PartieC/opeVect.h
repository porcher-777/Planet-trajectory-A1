#ifndef PROJETCIR1_GROUPE2_OPEVECT_H
#define PROJETCIR1_GROUPE2_OPEVECT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define G 6.67408e-11
#define MS 1.989e30
#define MT 5.972e24
#define ML 7.6e22

typedef struct s_Vector{
    double x;
    double y;
    double z;
} vector;

vector CalculerAddVecteur(vector Vect1, vector Vect2);
vector CalculerSubVecteur(vector Vect1, vector Vect2);
vector CalculerMulVecteur(vector Vect1, float scalaire);
float CalculerNormeVecteur(vector Vect);

vector vectorTest();

#endif
