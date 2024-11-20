cmake_minimum_required(VERSION 3.29)
project(gestionTour C)

set(CMAKE_C_STANDARD 23)

add_executable(gestionTour main.c
        gestionTour.c
        gestionTour.h)
