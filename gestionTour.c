//
// Created by rapha on 24/11/2024.
//
#include <stdio.h>
#include "gestionTour.h"
#include "plateau.h" // Assurez-vous que les fonctions d'affichage et de gestion du plateau sont définies ici
#include "AffichageHistorique.h" // Gestion de l'historique des actions
#include "Barrierepose.h"
#include "DeplacementPion.h"
#include "Deplacementregles.h"

void GestionTour(unsigned short int NBJoueurs,
                 char NomJoueurs[4][32],
                 unsigned short int TableauBarriereRest[4],
                 unsigned short int TableauP[9][9],
                 unsigned short int TableauB[8][8]) {
    unsigned short int joueurActuel = 0; // Indice du joueur actuel
    unsigned short int numeroTour = 1;  // Compteur pour le numéro de tour
    int jeuEnCours = 1;                 // Condition pour continuer la partie

    while (jeuEnCours) {
        printf("\n======================\n");
        printf("Tour %d\n", numeroTour);
        printf("======================\n");

        // Afficher la liste des joueurs et leurs barrières restantes
        printf("État actuel :\n");
        for (unsigned short int i = 0; i < NBJoueurs; i++) {
            printf("Joueur %d (%s) : %d barrières restantes\n",
                   i + 1, NomJoueurs[i], TableauBarriereRest[i]);
        }

        printf("\n--- Tour du joueur %d : %s ---\n", joueurActuel + 1, NomJoueurs[joueurActuel]);

        // Afficher le plateau
        afficher_plateau(TableauP, TableauB);

        // Choisir une action
        int choix;
        do {
            printf("\nChoisissez une action :\n");
            printf("1. Poser une barrière\n");
            printf("2. Déplacer votre pion\n");
            printf("3. Afficher l'historique\n");
            printf("4. Annuler un coup\n");
            printf("5. Quitter la partie\n");
            printf("Entrez votre choix : ");
            scanf("%d", &choix);

            if (choix == 1) {
                // Poser une barrière
                if (TableauBarriereRest[joueurActuel] > 0) {
                    unsigned short int x, y;
                    printf("Entrez les coordonnées (x y) pour poser une barrière : ");
                    scanf("%hu %hu", &x, &y);
                    if (poserBarriere(x, y, TableauB)) { // Appelle le programme `poseMur`
                        TableauBarriereRest[joueurActuel]--; // Décrémenter les barrières restantes
                        EnregistrerHistorique(joueurActuel, x, y, 1); // Enregistrer dans l'historique
                    } else {
                        printf("Action invalide. Réessayez.\n");
                        continue;
                    }
                } else {
                    printf("Vous n'avez plus de barrières disponibles.\n");
                }
            } else if (choix == 2) {
                // Déplacer le pion
                unsigned short int x, y;
                printf("Entrez les nouvelles coordonnées (x y) : ");
                scanf("%hu %hu", &x, &y);
                if (DeplacementPion(joueurActuel, x, y, TableauP)) { // Appelle le programme `deplacement`
                    EnregistrerHistorique(joueurActuel, x, y, 2); // Enregistrer dans l'historique
                } else {
                    printf("Déplacement invalide. Réessayez.\n");
                    continue;
                }
            } else if (choix == 3) {
                // Afficher l'historique
               void AffichageHistorique(); // Appelle le programme `affichageHistorique0`
            } else if (choix == 4) {
                /* Annuler un coup
                if (!Annulation()) { // Appelle le programme `annulation0`
                    printf("Aucun coup à annuler.\n");
                }*/
            } else if (choix == 5) {
                // Quitter la partie
                printf("Partie quittée par le joueur.\n");
                jeuEnCours = 0; // Arrêter la partie
                break;
            } else {
                printf("Choix invalide. Réessayez.\n");
            }
        } while (choix < 1 || choix > 5);

        // Vérifier les conditions de victoire (à implémenter dans `gestionPartie0`)
        if (PlacementRegles(joueurActuel, TableauP)) { // Fonction à implémenter
            printf("\nFélicitations ! %s a gagné la partie !\n", NomJoueurs[joueurActuel]);
            jeuEnCours = 0; // Arrêter la partie
            break;
        }

        // Passer au joueur suivant
        joueurActuel = (joueurActuel + 1) % NBJoueurs;

        // Incrémenter le numéro du tour si on revient au premier joueur
        if (joueurActuel == 0) {
            numeroTour++;
        }
    }
}

