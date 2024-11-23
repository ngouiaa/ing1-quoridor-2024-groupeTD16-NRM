cmake_minimum_required(VERSION 3.29)
project(AffichageHistorique C)

set(CMAKE_C_STANDARD 23)

add_executable(AffichageHistorique main.c
        AffichageHistorique.c
        AffichageHistorique.h)
