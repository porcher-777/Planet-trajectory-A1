#include "dessin_SDL.h"

int dessin(FILE* fichier, trajectoire astre, int n){
    bool quit = false;
    SDL_Event event;

    SDL_Window* fenetre;
    SDL_Renderer* renderer;//Déclaration du renderer

    if (SDL_VideoInit(NULL) < 0){ // Initialisation de la SDL
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Création de la fenêtre :
    fenetre = SDL_CreateWindow("Une fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, 0);
    if (fenetre == NULL){ // Gestion des erreurs
        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    //Création du renderer :
    renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer
    if (renderer == NULL){ //gestion des erreurs
        printf("Erreur lors de la creation d'un renderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    //Fond en noir
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //On met la texture du soleil sur le fond noir
    SDL_Surface * image = SDL_LoadBMP("sun1.bmp");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Rect dstrect = { 350, 250, 100, 100 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    //On met la texture de Mercure sur le fond noir
    SDL_Surface * image1 = SDL_LoadBMP("mercure.bmp");
    SDL_Texture * texture1 = SDL_CreateTextureFromSurface(renderer, image1);

    int i = 0;
    double x = 0, y = 0;

    while ( i != n){
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }
        //On affiche la planète à chaque point (comme avec le js)
        x = astre.tab_trajectoire[i].r.x * pow(10, -9) + 400;
        y = astre.tab_trajectoire[i].r.y * pow(10, -9) + 300;
        SDL_Rect dstrect1 = {x, y, 15, 15 };

        SDL_RenderCopy(renderer, texture1, NULL, &dstrect1);
        SDL_RenderPresent(renderer);
        //SDL_Delay(50);
        i++;
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit(); // On quitte la SDL
}
