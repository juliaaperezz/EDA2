cmake_minimum_required(VERSION 3.24)
project(EDA2_proyecto C)

set(CMAKE_C_STANDARD 11)

add_executable(EDA2_proyecto sources/src/main.c sources/src/funciones_menu.c sources/headers/funciones_menu.h sources/src/user_linked.c sources/headers/user_linked.h sources/src/menu.c sources/headers/menu.h sources/src/usuario.c sources/headers/usuario.h)
