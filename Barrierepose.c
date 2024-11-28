//
// Created by rapha on 24/11/2024.
//
#include <stdio.h>
#include "Barrierepose.h"
#include "Deplacementregles.h" // Inclure PlacementRegles pour valider les actions
#include "MAINN.h"           // Inclut les structures globales comme TableauB et TableauBarriereRest

// Fonction pour poser une barrière
void poserBarriere(const joueur, int x, int y, char orientation, joueur joueurs[], char grille[T][T]) {
    // Vérifier si le joueur a encore des barrières disponibles
    if (TableauBarriereRest[joueur] <= 0) {
        printf("Erreur : Le joueur %d n'a plus de barrières disponibles.\n", joueur + 1);
        return;
    }

    // Vérifier si la position de la barrière est valide avec PlacementRegles
    Barriere barriere = {x, y, orientation};
    if (!PlacementRegles(joueur, x, y, 2)) { // 2 = typeAction pour barrière
        printf("Erreur : La position (%d, %d) pour la barrière est invalide.\n", x, y);
        return;
    }

    // Vérifier la position avec la fonction verifier_position_barriere
    if (!verifier_position_barriere(&barriere, grille)) {
        printf("Impossible de poser la barrière : position invalide.\n");
        return;
    }

    // Si la position est valide, on place la barrière dans TableauB
    if (barriere.orientation == 'H') {
        grille[barriere.x][barriere.y] = '-';
        grille[barriere.x][barriere.y + 1] = '-';
    } else if (barriere.orientation == 'V') {
        grille[barriere.x][barriere.y] = '|';
        grille[barriere.x + 1][barriere.y] = '|';
    }

    // Mise à jour du nombre de barrières restantes pour le joueur dans TableauBarriereRest
    TableauBarriereRest[joueur]--;

    // Enregistrer la barrière placée dans le tableau
    joueurs[joueur].barrieres_placees[joueurs[joueur].nombre_barrieres_placees] = barriere;
    joueurs[joueur].nombre_barrieres_placees++;

    // Afficher le succès
    printf("La barrière du joueur %d a été placée en (%d, %d) avec orientation '%c'.\n", joueur + 1, x, y, orientation);
    printf("Il reste %d barrières au joueur %d.\n", TableauBarriereRest[joueur], joueur + 1);
}
