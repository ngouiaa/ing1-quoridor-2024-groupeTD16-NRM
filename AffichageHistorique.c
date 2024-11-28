//
// Created by rapha on 24/11/2024.
//

#include "AffichageHistorique.h"
#include <stdio.h>
#include "MAINN.h" // Inclure les déclarations des structures globales

// Fonction pour afficher l'historique des actions
void AfficherHistorique() {
    printf("\nHistorique des coups :\n");

    for (unsigned short int i = 0; i < 100; i++) {
        // Arrêter si aucune action n'est enregistrée
        if (TableauHistorique[i][0] == 0 && TableauHistorique[i][1] == 0) {
            break;
        }

        // Afficher le numéro du tour, le joueur et son action
        unsigned short int joueur = TableauHistorique[i][0]; // Index du joueur
        unsigned short int action = TableauHistorique[i][1]; // Type d'action

        printf("Tour %d - Joueur %d (%s) : ", i + 1, joueur + 1, NomJoueurs[joueur]);

        // Déterminer l'action (1 = poser une barrière, 2 = déplacer un pion)
        if (action == 1) {
            printf("Poser une barrière\n");
        } else if (action == 2) {
            printf("Déplacer le pion\n");
        } else {
            printf("erreur\n");
        }
    }
}
