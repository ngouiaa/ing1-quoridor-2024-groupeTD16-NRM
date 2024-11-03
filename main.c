#include <stdio.h>
#include <stdlib.h>
#include "tableauex.h"

int main() {
    int choix, x;
    do {
        printf("\n1 - Lancer une nouvelle partie\n");
        printf("2 - Reprendre une partie sauvergardée\n");
        printf("3 - Afficher l'aide\n");
        printf("4 - Afficher les scores des joueurs\n");
        printf("5 - Quitter le jeu\n");
        printf("\n\tChoisir une des options :");
        scanf("%d",&choix);
        switch(choix) {
            case 1 :
                
            break;
            case 2 :
                
            break;
            case 3 :
                
            break;
            case 4 :
                
            break;
            case 5 :
                printf("Au revoir !\n");
            break;
            default :
                printf("choix non valide !\n");
        }
    }while(choix != 5);
    return 0;
}








int main(void) {
    int p1[T][T];
    initialiser_plateau(p1,2);
    afficher_plateau(p1);
    return 0;

}
