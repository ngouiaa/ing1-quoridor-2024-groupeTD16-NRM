//
// Created by gouia on 20/11/2024.
//
#ifndef MAINN_H
#define MAINN_H
#ifndef HEADER_H
#define HEADER_H

// Déclarations des structures
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

#endif

#endif //MAINN_H
