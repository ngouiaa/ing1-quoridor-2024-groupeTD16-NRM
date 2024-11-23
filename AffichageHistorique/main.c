#include <stdio.h>
#include "AffichageHistorique.h"

// Déclaration des tableaux externes (ils sont définis ailleurs)
extern unsigned short int TableauP[9][9];      // Plateau des pions
extern unsigned short int TableauB[8][8];      // Plateau des barrières
extern unsigned short int TableauHistorique[100][3]; // Historique des actions
extern char NomJoueurs[4][32];                 // Noms des joueurs
extern unsigned short int NBJoueurs;           // Nombre de joueurs

// Fonction pour afficher les tableaux
void AfficherTableaux() {
    printf("\nTableau des positions des pions (9x9) :\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%2d ", TableauP[i][j]);
        }
        printf("\n");
    }

    printf("\nTableau des positions des barrières (8x8) :\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%2d ", TableauB[i][j]);
        }
        printf("\n");
    }

    printf("\nHistorique des coups :\n");
    for (int i = 0; i < 100; i++) {
        if (TableauHistorique[i][0] == 0 && TableauHistorique[i][1] == 0 && TableauHistorique[i][2] == 0) {
            break; // Arrêter l'affichage si aucune action enregistrée
        }

        printf("Tour %d - Joueur %d : ", i + 1, TableauHistorique[i][0] + 1);
        if (TableauHistorique[i][1] == 1) {
            printf("Poser une barrière\n");
        } else if (TableauHistorique[i][1] == 2) {
            printf("Déplacer le pion\n");
        }
    }

    printf("\nListe des joueurs :\n");
    for (int i = 0; i < NBJoueurs; i++) {
        printf("Joueur %d : %s\n", i + 1, NomJoueurs[i]);
    }
}
