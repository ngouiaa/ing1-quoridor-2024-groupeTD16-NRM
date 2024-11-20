#include <stdio.h>
#include "MAINN.h"

int main() {
    printf("Bienvenue dans le jeu Quoridor !\n");

    InitialiserStructures();
    ConfigurerJeu();

    printf("\nConfiguration du jeu :\n");
    printf("Nombre de joueurs : %d\n", NBJoueurs);
    for (unsigned short int i = 0; i < NBJoueurs; i++) {
        printf("Joueur %d : %s, Symbole: %d, Barrières restantes: %d\n",
               i + 1, NomJoueurs[i], TableauSymbole[i], TableauBarriereRest[i]);
    }


    return 0;
}
