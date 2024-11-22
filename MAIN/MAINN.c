//
// Created by gouia on 20/11/2024.
//

#include "MAINN.h"
#include <stdio.h>
#include <string.h>
#include "MAINN.h"

void InitialiserStructures() {
    memset(TableauP, 0, sizeof(TableauP));
    memset(TableauB, 0, sizeof(TableauB));
    memset(TableauHistorique, 0, sizeof(TableauHistorique));
    for (unsigned short int i = 0; i < 4; i++) {
        TableauBarriereRest[i] = 0;
        OrdreJeu[i] = i;
        TableauSymbole[i] = 0;
        strcpy(NomJoueurs[i], "");
    }
    NBJoueurs = 0;
}

void ConfigurerJeu() {
    do {
        printf("Entrez le nombre de joueurs (2 ou 4) : ");
        scanf("%hu", &NBJoueurs);
        if (NBJoueurs != 2 && NBJoueurs != 4) {
            printf("Erreur : le nombre de joueurs doit être 2 ou 4.\n");
        }
    } while (NBJoueurs != 2 && NBJoueurs != 4);

    for (unsigned short int i = 0; i < NBJoueurs; i++) {
        printf("Entrez le nom du joueur %d : ", i + 1);
        scanf("%s", NomJoueurs[i]);
    }

    unsigned short int barrieresParJoueur = (NBJoueurs == 2) ? 10 : 4;
    for (unsigned short int i = 0; i < NBJoueurs; i++) {
        TableauBarriereRest[i] = barrieresParJoueur;
    }

    for (unsigned short int i = 0; i < NBJoueurs; i++) {
        TableauSymbole[i] = i + 1;
    }
}

int ChoisirAction(unsigned short int joueur) {
    int choix;
    printf("Joueur %d, choisissez une action :\n", joueur + 1);
    printf("1. Poser une barrière\n");
    printf("2. Déplacer le pion\n");
    printf("Entrez votre choix (1 ou 2) : ");
    scanf("%d", &choix);

    while (choix != 1 && choix != 2) {
        printf("Choix invalide. Entrez 1 pour poser une barrière ou 2 pour déplacer le pion : ");
        scanf("%d", &choix);
    }
    return choix;
}
