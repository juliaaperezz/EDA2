//
// Created by julia on 09/05/2023.
//

#ifndef EDA2_PROYECTO_USUARIO_H
#define EDA2_PROYECTO_USUARIO_H

#endif //EDA2_PROYECTO_USUARIO_H

#define MAX_INTERESTS 5
#define MAX_LENGHT 100
#define MAX_USUARIOS 100

// Definición del typedef para el usuario
typedef struct {
    char nombreUsuario[MAX_LENGHT];
    int  edad;
    char correoElectronico[MAX_LENGHT];
    char ubicacion[MAX_LENGHT];
    char gustos[MAX_INTERESTS][MAX_LENGHT];
    struct NodoAmigo* amigos;
    struct NodoSolicitud* solicitudesAmistad;
} Usuario;

typedef struct NodoAmigo {
    struct Usuario* usuario;
    struct NodoAmigo* next;
} NodoAmigo;

typedef struct NodoSolicitud {
    struct Usuario* usuario;
    struct NodoSolicitud* next;
} NodoSolicitud;


// creamos esta estructura para poder crear una lista dinamica de los usuarios
typedef struct Node {
    Usuario usuario;  //queremos listar los usuarios
    struct Node* next;
    struct Node* prev;
} Node;

