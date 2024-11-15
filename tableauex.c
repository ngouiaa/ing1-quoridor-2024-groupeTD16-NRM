//
// Created by rapha on 22/10/2024.
//

#include "tableauex.h"
#include <stdio.h>
void initialiser_plateau(char plateau[T][T], int nj) {
    int i,j;
    for (i = 0; i < T; i++) {
        for(j=0; j < T; j++) {
            plateau[i][j] = 0;
        }
    }
    if(nj==2) {
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
                printf("|%c", ' ');
            else
                if (plateau [i][j] == 1)
                    printf("|%c", '0');
                else
                    if (plateau [i][j] == 2)
                        printf("|%c", '+');
        }
        printf("|\n");
        for (j = 0; j < T; j++) {
            printf("----");
        }
    }






}




