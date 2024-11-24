//
// Created by gouia on 19/11/2024.
//
#ifndef BARRIEREPOSE_H
#define BARRIEREPOSE_H
#define MAX_BARRIERES_2_JOUEURS 10 // Nombre de barrières pour 2 joueurs
#define MAX_BARRIERES_4_JOUEURS 5  // Nombre de barrières pour 4 joueurs
#define T 9            // Taille de la grille 9x9
#define MAX_JOUEURS 4  // Maximum de joueurs

// Structure pour représenter une barrière
typedef struct {
    int x;              // Coordonnée X (ligne)
    int y;              // Coordonnée Y (colonne)
    char orientation;   // Orientation : 'H' (horizontale) ou 'V' (verticale)
} Barriere;

// Initialisation des joueurs avec leurs barrières selon le nombre de joueurs
void initialiser_joueurs(Joueur joueurs[], int nb_joueurs);

// Vérifie si une position de barrière est valide
int verifier_position_barriere(const Barriere *barriere, char grille[T][T]);

// Fonction pour poser une barrière
void poserBarriere(int joueur, int x, int y, char orientation, Joueur joueurs[], char grille[T][T]);


#endif
