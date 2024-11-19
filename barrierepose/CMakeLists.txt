cmake_minimum_required(VERSION 3.29)
project(barrierepose C)

set(CMAKE_C_STANDARD 23)

add_executable(barrierepose main.c
        barrierepose.c
        barrierepose.h)
