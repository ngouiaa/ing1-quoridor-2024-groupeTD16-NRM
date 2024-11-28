#include <stdio.h>
#include"plateau.h"
#include"Barrierepose.h"
#include"Deplacementregles.h"
#include"gestionTour.h"
#include"GestionPartie.h"
#include"AffichageHistorique.h"
#include"MAINN.h"



int main() {
    int choix;
    int nbjoueur = 0;
    char noms[4][50];
    char plateau[T][T];
    int coup;
    do {
        printf("\tBienvenue dans le jeu Quoridor !\n");
        printf("\n1 - Lancer une nouvelle partie\n");
        printf("2 - Reprendre une partie sauvergardee\n");
        printf("3 - Afficher l'aide\n");
        printf("4 - Afficher les scores des joueurs\n");
        printf("5 - Quitter le jeu\n");
        printf("\n\tChoisir une des options :");
        scanf("%d",&choix);
        switch(choix) {
            case 1 :
                InitialiserPartie();
                initialiser_plateau;
                afficher_plateau;
                GererTour;
                ChoisirAction;
            EnregistrerHistorique();
            break;
            case 2 :
                sauvegarderPartie;
                chargerPartie;

                break;
            case 3 :
                PlacementRegles;

                break;
            case 4 :
                AfficherEtatJeu;

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


