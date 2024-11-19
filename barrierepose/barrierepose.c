//
// Created by gouia on 19/11/2024.
//
#include <stdio.h>
#include "barrierepose.h"

// Initialise les joueurs avec le nombre de barrières selon le nombre de joueurs
void initialiser_joueurs(Joueur joueurs[], int nb_joueurs) {
    int barrières_par_joueur = (nb_joueurs == 2) ? MAX_BARRIERES_2_JOUEURS : MAX_BARRIERES_4_JOUEURS;

    for (int i = 0; i < nb_joueurs; i++) {
        joueurs[i].barrieres_restantes = barrières_par_joueur;
        joueurs[i].nombre_barrieres_placees = 0;
    }
}

// Vérifie si une barrière peut être placée à une position donnée
int verifier_position_barriere(const Barriere *barriere, char grille[T][T]) {
    if (barriere->x < 0 || barriere->x >= T - 1 ||
        barriere->y < 0 || barriere->y >= T - 1) {
        printf("Position invalide : hors des limites de la grille.\n");
        return 0;
    }

    if (barriere->orientation == 'H') {
        if (grille[barriere->x][barriere->y] != ' ' || grille[barriere->x][barriere->y + 1] != ' ') {
            printf("Position invalide : conflit avec une barriere horizontale existante.\n");
            return 0;
        }
    } else if (barriere->orientation == 'V') {
        if (grille[barriere->x][barriere->y] != ' ' || grille[barriere->x + 1][barriere->y] != ' ') {
            printf("Position invalide : conflit avec une barriere verticale existante.\n");
            return 0;
        }
    } else {
        printf("Orientation invalide. Utilisez 'H' ou 'V'.\n");
        return 0;
    }

    return 1; // Position valide
}

// Place une barrière pour un joueur et met à jour la grille
void barrierepose(Joueur *joueur, const Barriere *barriere, char grille[T][T]) {
    if (joueur->barrieres_restantes <= 0) {
        printf("Aucune barriere restante pour ce joueur.\n");
        return;
    }

    if (!verifier_position_barriere(barriere, grille)) {
        printf("Impossible de poser la barriere.\n");
        return;
    }

    if (barriere->orientation == 'H') {
        grille[barriere->x][barriere->y] = '-';
        grille[barriere->x][barriere->y + 1] = '-';
    } else if (barriere->orientation == 'V') {
        grille[barriere->x][barriere->y] = '|';
        grille[barriere->x + 1][barriere->y] = '|';
    }

    joueur->barrieres_restantes--;
    joueur->barrieres_placees[joueur->nombre_barrieres_placees] = *barriere;
    joueur->nombre_barrieres_placees++;

    printf("Barriere posée avec succès en (%d, %d) avec orientation '%c'.\n",
           barriere->x, barriere->y, barriere->orientation);
}
