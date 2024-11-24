#include <stdio.h>
#include "poserBarrieres.h"
#include "MAINN.h"

// Initialisation du tableau des barrières
void InitialiserTableauB() {
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            TableauB[i][j] = 0; // Toutes les cases de barrières sont vides
        }
    }
}

int main() {
    // Initialisation du jeu
    Joueur joueurs[MAX_JOUEURS];
    initialiser_joueurs(joueurs, 2); // Initialiser 2 joueurs pour cet exemple

    char grille[T][T];
    InitialiserTableauB();  // Initialise la grille des barrières

    // Test : Joueur 1 place une barrière à (2, 3) horizontale
    printf("Test : Joueur 1 place une barrière en (2, 3) horizontale\n");
    poserBarriere(0, 2, 3, 'H', joueurs, grille);

    // Test : Joueur 1 essaie de placer une barrière à une position invalide (hors limites)
    printf("\nTest : Joueur 1 place une barrière en (8, 8) (hors limites)\n");
    poserBarriere(0, 8, 8, 'H', joueurs, grille);

    // Test : Joueur 2 place une barrière à (3, 4) verticale
    printf("\nTest : Joueur 2 place une barrière en (3, 4) verticale\n");
    poserBarriere(1, 3, 4, 'V', joueurs, grille);

    // Affichage de la grille après les placements
    printf("\nGrille après les placements de barrières :\n");
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            printf("%c ", grille[i][j]);
        }
        printf("\n");
    }

    return 0;
}

