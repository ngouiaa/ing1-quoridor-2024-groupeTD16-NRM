#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
#include <stdio.h>
#include "PlacementRegles.h"
#include "MAINN.h" // Inclut les structures globales comme TableauP et TableauB

// Initialiser les tableaux
void InitialiserTableaux() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            TableauP[i][j] = 0; // Plateau des pions vide
            if (i < 8 && j < 8) {
                TableauB[i][j] = 0; // Plateau des barrières vide
            }
        }
    }
}

int main() {
    // Initialisation des structures
    InitialiserTableaux();

    // Simulation de quelques actions
    int joueur = 0; // Joueur 1
    printf("Test : Déplacement de pion vers (4, 4)\n");
    if (PlacementRegles(joueur, 4, 4, 1)) {
        TableauP[4][4] = joueur + 1; // Déplacement valide, mise à jour de TableauP
        printf("Action validée : Le pion a été déplacé vers (4, 4).\n");
    }

    printf("\nTest : Placement de barrière en (2, 3)\n");
    if (PlacementRegles(joueur, 2, 3, 2)) {
        TableauB[2][3] = 1; // Placement valide, mise à jour de TableauB
        printf("Action validée : La barrière a été placée en (2, 3).\n");
    }

    printf("\nTest : Placement de barrière en (2, 3) (déjà occupée)\n");
    if (!PlacementRegles(joueur, 2, 3, 2)) {
        printf("Action refusée : La barrière ne peut pas être placée ici.\n");
    }

    return 0;
}
