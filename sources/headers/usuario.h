//
// Created by julia on 09/05/2023.
//

#ifndef EDA2_PROYECTO_USUARIO_H
#define EDA2_PROYECTO_USUARIO_H

#define MAX_INTERESTS 5
#define MAX_LENGTH 100
#define MAX_USUARIOS 100

// Definición del typedef para el usuario
typedef struct {
    char nombreUsuario[MAX_LENGTH];
    int  edad;
    char correoElectronico[MAX_LENGTH];
    char ubicacion[MAX_LENGTH];
    int gustos[MAX_INTERESTS];
} Usuario;

// definicion de funciones


#endif //EDA2_PROYECTO_USUARIO_H

