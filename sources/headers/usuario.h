//
// Created by julia on 09/05/2023.
//

#ifndef EDA2_PROYECTO_USUARIO_H
#define EDA2_PROYECTO_USUARIO_H

#endif //EDA2_PROYECTO_USUARIO_H


#define MAX_INTERESTS 5
#define MAX_LENGHT 100
#define MAX_USUARIOS 100

#include <stdio.h>
#include <stdlib.h>
#include "funciones_menu.h"
#include "menu.h"
#include "../src/menu.c"
#include "../src/main.c"

// Definición del typedef para el usuario
typedef struct {
    char nombreUsuario[MAX_LENGHT];
    int  edad;
    char correoElectronico[MAX_LENGHT];
    char ubicacion[MAX_LENGHT];
    char gustos[MAX_INTERESTS][MAX_LENGHT];
} Usuario;
