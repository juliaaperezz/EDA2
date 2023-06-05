cmake_minimum_required(VERSION 3.24)
project(EDA2_proyecto C)

set(CMAKE_C_STANDARD 11)

add_executable(EDA2_proyecto sources/src/menu.c sources/headers/menu.h sources/src/usuario.c sources/headers/usuario.h sources/src/main.c sources/headers/main.h "sources/src/funciones submenu.c" "sources/headers/funciones submenu.h" "sources/src/documento 2.c" "sources/headers/documento 2.h" "sources/src/document r.c" "sources/headers/document r.h")
