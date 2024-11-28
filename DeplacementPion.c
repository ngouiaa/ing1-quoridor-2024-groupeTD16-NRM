//
// Created by rapha on 24/11/2024.
//

#include "DeplacementPion.h"
#include <stdio.h>
#include "DeplacementRegles.h" // Vérification des règles
#include "MAINN.h"           // Structures globales, y compris TableauP

// Prototype de GestionPlacement (définie dans un autre module)
extern int GestionPlacement(int joueur, int x, int y);

void DeplacementPion(int joueur, int x, int y) {
    // Vérification des règles via PlacementRegles
    if (!PlacementRegles(joueur, x, y, 1)) { // 1 = typeAction pour déplacement
        printf("Déplacement invalide pour le joueur %d vers (%d, %d).\n", joueur + 1, x, y);
        return;
    }

    // Gestion du déplacement via GestionPlacement
    if (!GestionPlacement(joueur, x, y)) {
        printf("GestionPlacement a refusé le déplacement pour le joueur %d.\n", joueur + 1);
        return;
    }

    // Effacer l'ancienne position du pion
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (TableauP[i][j] == joueur + 1) { // Identifie le pion du joueur
                TableauP[i][j] = 0;            // Efface l'ancienne position
            }
        }
    }

    // Mettre à jour la nouvelle position dans TableauP
    TableauP[x][y] = joueur + 1;

    // Confirmation du déplacement
    printf("Le pion du joueur %d a été déplacé vers (%d, %d).\n", joueur + 1, x, y);
}
