#include "Tableau.h"
#include <stdio.h>
void initialiser_plateau(char plateau[T][T], int nbjoueur) {
    int i,j;
    for (i = 0; i < T; i++) {
        for(j=0; j < T; j++) {
            plateau[i][j] = 0;
        }
    }
    if(nbjoueur==2) {
        plateau[0][T/2] = 1;
        plateau[T-1][4] = 2;
    }
    else {
        plateau[0][0] = 1;
        plateau[0][T-1] = 2;
        plateau[T-1][0] = 3;
        plateau[T-1][T-1] = 4;
    }
}
void afficher_plateau(char plateau[T][T]) {
    int i,j;
    for (i = 0; i < T; i++) {
        for (j = 0; j < T; j++) {
            if(plateau[i][j] == 0)
                printf("| -%c", ' ');
            else
                if (plateau [i][j] == 1)
                    printf("| %c ", '0');
                else
                    if (plateau [i][j] == 2)
                        printf("| %c ", '+');
                    else
                        if (plateau [i][j] == 3)
                            printf("| %c ", '@');
                        else
                            if (plateau [i][j] == 4)
                                printf("| %c ", '#');
        }
        printf("|\n");
    }
}

void nom_joueurs(int *nbjoueur,char noms[4][50]) {
    do {
        printf("jouer a 2 OU 4 :");
        scanf("%d",nbjoueur);
        if(*nbjoueur !=4 && *nbjoueur !=2) {
            printf("Nombre invalide ! jouer a 2 OU 4 :");
        }
    }while(*nbjoueur!=4 && *nbjoueur!=2);
    for(int i=0;i<*nbjoueur;i++) {
        printf("Nom du joueur %d : ", i+1);
        scanf("%s",noms[i]);
    }
    printf("\nListe des joueurs :\n");
    for(int i=0; i<*nbjoueur; i++) {
        printf("Joueur %d : %s\n", i+1,noms[i]);
    }
}

void

/* Initialise les joueurs avec le nombre de barrières selon le nombre de joueurs
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
}*/

