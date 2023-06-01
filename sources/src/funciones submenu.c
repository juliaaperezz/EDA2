//
// Created by julia on 01/06/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones submenu.h"
#include "../headers/menu.h"
#include "../headers/usuario.h"
#include "../headers/main.h"


//PARA OPCIÓN: enviar solicitud de amistad
//inizialización funciones
Usuario* buscarUsuario(Node* lista, char* nombreUsuario);
void enviarSolicitudAmistad(Node* listaUsuarios, Usuario* usuario, char* nombreUsuarioAmigo);
void agregarSolicitudAmistad(Usuario* amigo, Usuario* solicitante);
int esAmigo(Usuario* usuario, Usuario* posibleAmigo);


void enviarSolicitudAmistad(Node* listaUsuarios, Usuario* usuario, char* nombreUsuarioAmigo) {
    Usuario* amigo = buscarUsuario(listaUsuarios, nombreUsuarioAmigo);
    if (amigo != NULL) {
        // Verificar si ya son amigos
        if (esAmigo(usuario, amigo)) {
            printf("Ya eres amigo de %s.\n", amigo->nombreUsuario);
        } else {
            // Enviar solicitud de amistad
            agregarSolicitudAmistad(amigo, usuario);
            printf("Solicitud de amistad enviada a %s.\n", amigo->nombreUsuario);
        }
    } else {
        printf("No se encontró el usuario con el nombre especificado.\n");
    }
}

//agrega la solicitud (el struct del usuario) a la lista enlazada al struct del usuario(al que se quiere enviar la solicitud)
void agregarSolicitudAmistad(Usuario* amigo, Usuario* solicitante) {
    if (amigo->solicitudesAmistad == NULL) {
        amigo->solicitudesAmistad = (NodoSolicitud*)malloc(sizeof(NodoSolicitud));
        amigo->solicitudesAmistad->usuario = solicitante;
        amigo->solicitudesAmistad->next = NULL;
    } else {
        NodoSolicitud* actual = amigo->solicitudesAmistad;
        while (actual->next != NULL) {
            actual = actual->next;
        }
        NodoSolicitud* nuevoNode = (NodoSolicitud*)malloc(sizeof(NodoSolicitud));
        nuevoNode->usuario = solicitante;
        nuevoNode->next = NULL;
        actual->next = nuevoNode;
    }
}

//función que verifica si ya son amigos
int esAmigo(Usuario* usuario, Usuario* posibleAmigo) {
    NodoAmigo* actual = usuario->amigos;
    while (actual != NULL) {
        if (actual->usuario == posibleAmigo) {
            return 1;  // Son amigos
        }
        actual = actual->next;
    }
    return 0;  // No son amigos
}





/*

void agregarAmigoDesconocido(Node* listaUsuarios, Usuario* usuario) {
    // Crear una pila de usuarios no amigos
    Node* pilaUsuariosNoAmigos = NULL;

    Node* actual = listaUsuarios;
    while (actual != NULL) {
        if (!esAmigo(usuario, &(actual->usuario))) {
            push(&pilaUsuariosNoAmigos, &(actual->usuario));
        }
        actual = actual->next;
    }

    // Mostrar usuarios aleatorios y agregar como amigos
    int contador = 0;
    while (pilaUsuariosNoAmigos != NULL && contador < 3) {
        Node* usuarioAleatorio = pop(&pilaUsuariosNoAmigos);
        agregarAmigo(usuario, usuarioAleatorio->usuario);
        contador++;
    }

    // Mostrar usuarios agregados como amigos
    // ...
}

*/


