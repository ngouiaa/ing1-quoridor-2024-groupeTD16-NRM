//
// Created by rapha on 24/11/2024.
//

#ifndef PLATEAU_H
#define PLATEAU_H
#define T 9 // Taille de la grille (9x9)
/*#define MAX_BARRIERES_2_JOUEURS 10 // Nombre de barrières pour 2 joueurs
#define MAX_BARRIERES_4_JOUEURS 5  // Nombre de barrières pour 4 joueurs
#define MAX_JOUEURS 4              // Maximum de joueurs*/


// Initialiser le plateau de jeu
void initialiser_plateau(char plateau[T][T], int nj);

// Afficher le tableau
void afficher_plateau(char plateau[T][T]);

#endif //PLATEAU_H
