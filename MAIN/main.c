#include <stdio.h>
#include "MAINN.h"
#include "AffichageHistorique.h"
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

    // Simuler une séquence de jeu
    printf("\nDébut du jeu :\n");
    for (unsigned short int i = 0; i < NBJoueurs; i++) {
        // Chaque joueur choisit une action
        int action = ChoisirAction(i);

        // Enregistrer l'action dans l'historique
        EnregistrerHistorique(i, action);

        // Afficher un résumé de l'action
        if (action == 1) {
            printf("Joueur %s a posé une barrière.\n", NomJoueurs[i]);
        } else if (action == 2) {
            printf("Joueur %s a déplacé son pion.\n", NomJoueurs[i]);
        }
    }

    // Afficher l'historique des actions jouées
    AfficherHistorique();

    return 0;
}
