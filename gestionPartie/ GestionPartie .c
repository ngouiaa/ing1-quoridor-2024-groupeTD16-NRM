//
// Created by gouia on 24/11/2024.
//

#include " GestionPartie .h"
#include <stdio.h>
#include "MAINN.h" // Inclure les structures globales

// Fonction pour initialiser la partie
void InitialiserPartie() {
    InitialiserStructures(); // Réinitialise toutes les structures globales
    ConfigurerJeu();         // Configure le jeu (nombre de joueurs, noms, etc.)
    printf("\nLa partie est initialisée !\n");
}

// Fonction pour gérer un tour
void GererTour(unsigned short int tour) {
    unsigned short int joueur = OrdreJeu[tour % NBJoueurs]; // Détermine le joueur actif
    printf("\nTour %d : C'est au joueur %d (%s) de jouer.\n", tour + 1, joueur + 1, NomJoueurs[joueur]);

    // Le joueur choisit une action
    int action = ChoisirAction(joueur);

    // Enregistrer l'action dans l'historique
    EnregistrerHistorique(joueur, action);

    // Mise à jour des murs restants si l'action est "poser une barrière"
    if (action == 1) {
        if (TableauBarriereRest[joueur] > 0) {
            TableauBarriereRest[joueur]--;
            printf("Joueur %s a posé une barrière. Barrières restantes : %d\n",
                   NomJoueurs[joueur], TableauBarriereRest[joueur]);
        } else {
            printf("Joueur %s n'a plus de barrières disponibles !\n", NomJoueurs[joueur]);
        }
    } else if (action == 2) {
        printf("Joueur %s a déplacé son pion.\n", NomJoueurs[joueur]);
    }
}

// Fonction pour afficher l'état général du jeu
void AfficherEtatJeu(unsigned short int tour) {
    printf("\nÉtat actuel de la partie :\n");
    printf("Tour actuel : %d\n", tour + 1);

    // Afficher les informations des joueurs
    for (unsigned short int i = 0; i < NBJoueurs; i++) {
        printf("Joueur %d (%s) : %d barrières restantes\n", i + 1, NomJoueurs[i], TableauBarriereRest[i]);
    }
}
