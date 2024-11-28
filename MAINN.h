//
// Created by rapha on 24/11/2024.
//

#ifndef MAINN_H
#define MAINN_H
extern unsigned short int TableauP[9][9];
extern unsigned short int TableauB[8][8];
extern char NomJoueurs[4][32];
extern unsigned short int NBJoueurs;
extern unsigned short int TableauBarriereRest[4];
extern unsigned short int OrdreJeu[4];
extern unsigned short int TableauHistorique[100][3];
extern unsigned short int TableauSymbole[4];

// Prototypes des fonctions
void InitialiserStructures();
void ConfigurerJeu();
int ChoisirAction(unsigned short int joueur);
void sauvegarderPartie(const char *nomFichier, unsigned short int tour);
void chargerPartie(const char *nomFichier, unsigned short int *tour);
#endif //MAINN_H
