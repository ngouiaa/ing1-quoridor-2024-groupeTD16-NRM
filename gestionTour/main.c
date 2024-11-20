#include "GestionTour.h"

int main() {
    InitialiserStructures(); // Initialiser les données du jeu
    ConfigurerJeu();         // Configurer les joueurs et les barrières

    // Démarrer la gestion des tours
    GestionTour(NBJoueurs, NomJoueurs, TableauBarriereRest, TableauP, TableauB);

    return 0;
}
