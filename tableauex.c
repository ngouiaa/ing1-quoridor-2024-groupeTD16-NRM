//
// Created by rapha on 22/10/2024.
//

#include "tableauex.h"
#include <stdio.h>
void initialiser_plateau(char plateau[T][T], int nbjoueur) {
    int i,j;
    for (i = 0; i < T; i++) {
        for(j=0; j < T; j++) {
            plateau[i][j] = 0;
        }
    }
    if(nbjoueur==2) {
        plateau[0][T/2] = 1;
        plateau[T-1][4] = 2;
    }
    else {
        plateau[0][0] = 1;
        plateau[0][T-1] = 2;
        plateau[T-1][0] = 3;
        plateau[T-1][T-1] = 4;
    }
}
void afficher_plateau(char plateau[T][T]) {
    int i,j;
    for (i = 0; i < T; i++) {
        for (j = 0; j < T; j++) {
            if(plateau[i][j] == 0)
                printf("| -%c", ' ');
            else
                if (plateau [i][j] == 1)
                    printf("| %c ", '0');
                else
                    if (plateau [i][j] == 2)
                        printf("| %c ", '+');
                    else
                        if (plateau [i][j] == 3)
                            printf("| %c ", '@');
                        else
                            if (plateau [i][j] == 4)
                                printf("| %c ", '#');
        }
        printf("|\n");
    }
}
typedef struct {
    int x;
    int y;
} Position;

void deplacerPion(Position *pion, char direction) {
    switch (direction) {
        case 'z': pion->x--; break; // Haut
        case 's': pion->x++; break; // Bas
        case 'q': pion->y--; break; // Gauche
        case 'd': pion->y++; break; // Droite
        default: printf("Direction invalide !\n"); break;
    }

    // Vérification des limites du tableau
    if (pion->x < 0) pion->x = 0;
    if (pion->x >= T) pion->x = T - 1;
    if (pion->y < 0) pion->y = 0;
    if (pion->y >= T) pion->y = T - 1;
}




