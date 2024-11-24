#include <stdio.h>
#include "GestionPartie.h"
#include "MAINN.h" // Inclut les structures

int main() {
    printf("=== TEST DU MODULE GESTIONPARTIE ===\n");

    // Initialiser la partie (initialise les structures globales et configure le jeu)
    InitialiserPartie();

    unsigned short int tour = 0; // Compteur de tours

    // Boucle de jeu simple
    while (1) {
        // Affiche l'état du jeu actuel
        AfficherEtatJeu(tour);

        // Gère le tour du joueur actif
        GererTour(tour);

        // Exemple de condition d'arrêt (limite arbitraire de 5 tours pour ce test)
        if (tour >= 5) {
            printf("\n=== Fin du test apres 5 tours ===\n");
            break;
        }

        tour++; // Passer au tour suivant
    }

    // Afficher l'historique des actions pour vérifier les enregistrements
    printf("\n=== Historique des actions ===\n");
    AfficherHistorique();

    return 0;
}
