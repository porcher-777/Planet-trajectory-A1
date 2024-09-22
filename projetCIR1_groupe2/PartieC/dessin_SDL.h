#ifndef PROJETCIR1_GROUPE2_DESSIN_SDL_H
#define PROJETCIR1_GROUPE2_DESSIN_SDL_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "methode.h"

#define WINDOW_W 800
#define WINDOW_H 600

int dessin(FILE* fichier, trajectoire astre, int n);

#endif