#include <stdio.h>
#include "DeplacementPion.h"
#include "MAINN.h"

// Exemple de GestionPlacement (pour test uniquement)
int GestionPlacement(int joueur, int x, int y) {
    // Valide le déplacement si la case est vide
    if (TableauP[x][y] == 0) {
        return 1; // Déplacement valide
    }
    printf("Erreur : La case (%d, %d) est occupée !\n", x, y);
    return 0; // Déplacement non valide
}

// Initialiser le tableau des pions
void InitialiserTableauP() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            TableauP[i][j] = 0; // Toutes les cases sont vides
        }
    }
    // Placer les pions initiaux
    TableauP[0][4] = 1; // Joueur 1 au centre de la première rangée
    TableauP[8][4] = 2; // Joueur 2 au centre de la dernière rangée
}

int main() {
    // Initialisation
    InitialiserTableauP();

    // Affichage initial
    printf("État initial du plateau :\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", TableauP[i][j]);
        }
        printf("\n");
    }

    // Déplacement du pion du joueur 1
    printf("\nTest : Déplacement du joueur 1 vers (1, 4)\n");
    DeplacementPion(0, 1, 4); // Joueur 1 se déplace à (1, 4)

    // Affichage après déplacement
    printf("\nÉtat du plateau après le déplacement :\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", TableauP[i][j]);
        }
        printf("\n");
    }

    return 0;
}
