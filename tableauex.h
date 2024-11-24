//
// Created by rapha on 22/10/2024.
//

#ifndef TABLEAUEX_H
#define TABLEAUEX_H
#define T 9
/*initialise la matrice (le plateau)
entree: la matrice et le nombre de joueur
sortie: rien
*/
#include"tableauex.c"
void initialiser_plateau(char plateau[T][T], int nj);
void afficher_plateau(char plateau[T][T]);
void deplacerPion(Position *pion, char direction);













#endif //TABLEAUEX_H
