#include <stdio.h>
#include <string.h>
#include "MAINN.h"

// Sauvegarder l'état actuel de la partie dans un fichier
void sauvegarderPartie(const char *nomFichier, unsigned short int tour) {
    FILE *fichier = fopen(nomFichier, "wb");
    if (!fichier) {
        printf("Erreur : Impossible d'ouvrir le fichier %s pour la sauvegarde.\n", nomFichier);
        return;
    }

    // Sauvegarder le tour actuel
    fwrite(&tour, sizeof(unsigned short int), 1, fichier);

    // Sauvegarder le nombre de joueurs
    fwrite(&NBJoueurs, sizeof(unsigned short int), 1, fichier);

    // Sauvegarder les noms des joueurs
    fwrite(NomJoueurs, sizeof(NomJoueurs), 1, fichier);

    // Sauvegarder les barrières restantes
    fwrite(TableauBarriereRest, sizeof(TableauBarriereRest), 1, fichier);

    // Sauvegarder le tableau des pions
    fwrite(TableauP, sizeof(TableauP), 1, fichier);

    // Sauvegarder le tableau des barrières
    fwrite(TableauB, sizeof(TableauB), 1, fichier);

    // Sauvegarder l'historique
    fwrite(TableauHistorique, sizeof(TableauHistorique), 1, fichier);

    // Sauvegarder l'ordre des joueurs
    fwrite(OrdreJeu, sizeof(OrdreJeu), 1, fichier);

    fclose(fichier);
    printf("Partie sauvegardée avec succès dans le fichier %s.\n", nomFichier);
}

// Charger l'état d'une partie à partir d'un fichier
void chargerPartie(const char *nomFichier, unsigned short int *tour) {
    FILE *fichier = fopen(nomFichier, "rb");
    if (!fichier) {
        printf("Erreur : Impossible d'ouvrir le fichier %s pour le chargement.\n", nomFichier);
        return;
    }

    // Charger le tour actuel
    fread(tour, sizeof(unsigned short int), 1, fichier);

    // Charger le nombre de joueurs
    fread(&NBJoueurs, sizeof(unsigned short int), 1, fichier);

    // Charger les noms des joueurs
    fread(NomJoueurs, sizeof(NomJoueurs), 1, fichier);

    // Charger les barrières restantes
    fread(TableauBarriereRest, sizeof(TableauBarriereRest), 1, fichier);

    // Charger le tableau des pions
    fread(TableauP, sizeof(TableauP), 1, fichier);

    // Charger le tableau des barrières
    fread(TableauB, sizeof(TableauB), 1, fichier);

    // Charger l'historique
    fread(TableauHistorique, sizeof(TableauHistorique), 1, fichier);

    // Charger l'ordre des joueurs
    fread(OrdreJeu, sizeof(OrdreJeu), 1, fichier);

    fclose(fichier);
    printf("Partie chargée avec succès depuis le fichier %s.\n", nomFichier);
}
