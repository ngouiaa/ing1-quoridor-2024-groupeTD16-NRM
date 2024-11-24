#ifndef TABLEAUEX_H
#define TABLEAUEX_H

#endif //TABLEAUEX_H
#define T 9 // Taille de la grille (9x9)
/*#define MAX_BARRIERES_2_JOUEURS 10 // Nombre de barrières pour 2 joueurs
#define MAX_BARRIERES_4_JOUEURS 5  // Nombre de barrières pour 4 joueurs
#define MAX_JOUEURS 4              // Maximum de joueurs*/


// Initialiser le plateau de jeu
void initialiser_plateau(char plateau[T][T], int nj);

// Afficher le tableau
void afficher_plateau(char plateau[T][T]);

// Choisir le nombre de joueur, le nom des joueurs et afficher la liste des joueurs
void nom_joueurs(int *nbjoueur,char noms[4][50]);

//Choisir entre

/* Initialisation des joueurs avec leurs barrières selon le nombre de joueurs
void initialiser_joueurs(Joueur joueurs[], int nb_joueurs);

// Vérifie si une position de barrière est valide
int verifier_position_barriere(const Barriere *barriere, char grille[T][T]);

// Place une barrière pour un joueur dans la grille
void barrierepose(Joueur *joueur, const Barriere *barriere, char grille[T][T]);


// Structure pour représenter une barrière
typedef struct {
    int x;              // Coordonnée X (ligne)
    int y;              // Coordonnée Y (colonne)
    char orientation;   // Orientation : 'H' (horizontale) ou 'V' (verticale)
} Barriere;

// Structure pour représenter un joueur
typedef struct {
    int barrieres_restantes;                       // Nombre de barrières restantes
    Barriere barrieres_placees[MAX_BARRIERES_2_JOUEURS]; // Liste des barrières placées (max pour 2 joueurs)
    int nombre_barrieres_placees;                  // Nombre total de barrières déjà posées
} Joueur;*/
