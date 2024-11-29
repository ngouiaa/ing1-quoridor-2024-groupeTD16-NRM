cmake_minimum_required(VERSION 3.29)
project(projet_info_test4 C)

set(CMAKE_C_STANDARD 11)

add_executable(projet_info_test4 main.c
        header.h
        Barriere.c
        Conversion.c
        deplacement.c
        Joueur.c
        Sauvegarde.c
        Affichage.c
        Timer.c)
