//
// Created by julia on 09/05/2023.
//
#ifndef EDA2_PROYECTO_USUARIO_H
#define EDA2_PROYECTO_USUARIO_H

#endif //EDA2_PROYECTO_USUARIO_H

#define MAX_INTERESTS 5
#define MAX_LENGHT 50
#define MAX_USUARIOS 100
#define MAX_PUBLICACIONES 100

typedef struct NodoPublicacion {
    char contenido[MAX_LENGHT];
    struct NodoPublicacion* siguiente;
} NodoPublicacion;

// Definición del typedef para el usuario
typedef struct {
    char nombreUsuario[MAX_LENGHT];
    int  edad;
    char correoElectronico[MAX_LENGHT];
    char ubicacion[MAX_LENGHT];
    char gustos[MAX_INTERESTS][MAX_LENGHT];
    struct NodoAmigo* amigos;
    struct NodoSolicitud* solicitudesAmistad;
    struct NodoPublicacion* publicaciones; // Lista de publicaciones del usuario
} Usuario;

// Estructura para representar un amigo en la lista de amigos de un usuario
typedef struct NodoAmigo {
    struct Usuario* usuario;
    struct NodoAmigo* next;
} NodoAmigo;

// Estructura para representar una solicitud de amistad en la lista de solicitudes pendientes de un usuario
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

