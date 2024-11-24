#include <stdio.h>
#include "MAINN.h"
#include "AffichageHistorique.h"
#include "GestionTours.h"

// Prototype pour la fonction de sauvegarde
void sauvegarderPartie(const char *nomFichier, unsigned short int tour);

int main() {
    printf("Bienvenue dans le jeu Quoridor !\n");

    // Initialisation des structures de données
    InitialiserStructures();

    // Configuration du jeu : nombre de joueurs, noms, symboles, barrières
    ConfigurerJeu();

    // Afficher la configuration initiale
    printf("\nConfiguration du jeu :\n");
    printf("Nombre de joueurs : %d\n", NBJoueurs);
    for (unsigned short int i = 0; i < NBJoueurs; i++) {
        printf("Joueur %d : %s, Symbole: %d, Barrières restantes: %d\n",
               i + 1, NomJoueurs[i], TableauSymbole[i], TableauBarriereRest[i]);
    }

    unsigned short int tour = 0; // Variable pour suivre le tour actuel
    int continuer = 1;          // Contrôle du jeu

    // Boucle principale du jeu
    while (continuer) {
        printf("\nTour %d - Joueur %d : %s\n", tour + 1, OrdreJeu[tour % NBJoueurs] + 1, NomJoueurs[OrdreJeu[tour % NBJoueurs]]);

        // Chaque joueur choisit une action
        int action = ChoisirAction(OrdreJeu[tour % NBJoueurs]);

        // Enregistrer l'action dans l'historique
        EnregistrerHistorique(OrdreJeu[tour % NBJoueurs], action);

        // Afficher un résumé de l'action
        if (action == 1) {
            printf("Joueur %s a posé une barrière.\n", NomJoueurs[OrdreJeu[tour % NBJoueurs]]);
        } else if (action == 2) {
            printf("Joueur %s a déplacé son pion.\n", NomJoueurs[OrdreJeu[tour % NBJoueurs]]);
        }

        // Option de sauvegarde
        printf("\nVoulez-vous sauvegarder la partie ? (1 = Oui, 0 = Non) : ");
        int sauvegarder = 0;
        scanf("%d", &sauvegarder);

        if (sauvegarder) {
            sauvegarderPartie("quoridor_save.dat", tour);
        }

        // Option pour continuer ou terminer la partie
        printf("\nVoulez-vous continuer la partie ? (1 = Oui, 0 = Non) : ");
        scanf("%d", &continuer);

        if (continuer == 0) {
            printf("Fin de la partie.\n");
            break;
        }

        // Passer au tour suivant
        tour++;
    }

    // Afficher l'historique des actions jouées
    AfficherHistorique();

    return 0;
}
