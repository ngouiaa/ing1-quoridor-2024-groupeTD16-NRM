//
// Created by rapha on 24/11/2024.
//

#include "Deplacementregles.h"
#include <stdio.h>
#include "Deplacementregles.h"
#include "MAINN.h" // Inclure les structures globales, comme TableauP et TableauB

/*
 * Vérifie si l'action est autorisée :
 * typeAction : 1 = Déplacement de pion, 2 = Placement de barrière
 * Retourne 1 si l'action est autorisée, 0 sinon.
 */
int PlacementRegles(int joueur, int x, int y, int typeAction) {
    // Vérifier les limites du plateau (9x9 pour les pions, 8x8 pour les barrières)
    if (x < 0 || y < 0 || x >= 9 || y >= 9) {
        printf("Erreur : Position (%d, %d) hors limites !\n", x, y);
        return 0; // Action non autorisée
    }

    if (typeAction == 1) { // Déplacement de pion
        // Vérifier que la case est vide
        if (TableauP[x][y] != 0) {
            printf("Erreur : La case (%d, %d) est déjà occupée par un autre pion !\n", x, y);
            return 0;
        }
        // (Optionnel) Vérifier que le déplacement est adjacent (pas de saut interdit)
        return 1; // Déplacement autorisé

    } else if (typeAction == 2) { // Placement de barrière
        // Vérifier que la position est dans le tableau des barrières (8x8)
        if (x >= 8 || y >= 8) {
            printf("Erreur : Position de barrière (%d, %d) hors limites !\n", x, y);
            return 0;
        }
        // Vérifier que la case de barrière est libre
        if (TableauB[x][y] != 0) {
            printf("Erreur : Une barrière est déjà placée en (%d, %d) !\n", x, y);
            return 0;
        }
        return 1; // Placement de barrière autorisé
    }

    printf("Erreur : Type d'action inconnu !\n");
    return 0; // Action non autorisée
}
