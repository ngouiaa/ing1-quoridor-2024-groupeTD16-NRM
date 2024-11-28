cmake_minimum_required(VERSION 3.29)
project(projetinfo C)

set(CMAKE_C_STANDARD 11)

add_executable(projetinfo main.c
        AffichageHistorique.h
        AffichageHistorique.c
        DeplacementPion.c
        Deplacementregles.h
        Barrierepose.h
        Barrierepose.c
        GestionPartie.h
        GestionPartie.c
        gestionTour.h
        plateau.h
        plateau.c
        sauvegardePartie.c
        MAINN.c
        gestionTour.c
        Deplacementregles.c
)
