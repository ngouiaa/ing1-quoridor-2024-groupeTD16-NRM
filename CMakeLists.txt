cmake_minimum_required(VERSION 3.29)
project(tableau C)

set(CMAKE_C_STANDARD 11)

add_executable(tableau main.c
        tableauex.c
        tableauex.h)
