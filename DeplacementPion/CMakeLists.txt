cmake_minimum_required(VERSION 3.29)
project(DeplacementPion C)

set(CMAKE_C_STANDARD 23)

add_executable(DeplacementPion main.c
        DeplacementPion.c
        DeplacementPion.h)
