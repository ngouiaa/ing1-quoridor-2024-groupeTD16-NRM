#include <stdio.h>
#include "barrierepose.h"

int main() {
    int nb_joueurs;
    do {
        printf("Entrez le nombre de joueurs (2 ou 4) : ");
        scanf("%d", &nb_joueurs);
    } while (nb_joueurs != 2 && nb_joueurs != 4);

    // Initialisation des joueurs
    Joueur joueurs[MAX_JOUEURS];
    initialiser_joueurs(joueurs, nb_joueurs);

    // Initialisation de la grille
    char grille[T][T];
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            grille[i][j] = ' ';
        }
    }

    // Tour de jeu (exemple simplifié)
    for (int tour = 0; tour < 2 * nb_joueurs; tour++) {
        int joueur_actuel = tour % nb_joueurs;
        printf("\nJoueur %d, barrieres restantes : %d\n",
               joueur_actuel + 1, joueurs[joueur_actuel].barrieres_restantes);

        // Lecture des coordonnées de la barrière
        Barriere barriere;
        printf("Entrez la position de la barriere (x y orientation) : ");
        scanf("%d %d %c", &barriere.x, &barriere.y, &barriere.orientation);

        // Pose de la barrière
        barrierepose(&joueurs[joueur_actuel], &barriere, grille);

        // Affichage de la grille
        printf("Etat de la grille :\n");
        for (int i = 0; i < T; i++) {
            for (int j = 0; j < T; j++) {
                printf("%c ", grille[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
