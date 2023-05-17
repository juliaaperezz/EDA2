//
// Created by julia on 09/05/2023.
//

#include "../headers/funciones_menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "usuario.c"
#include "user_linked.c"
#include "../headers/usuario.h"
#include "menu.c"



// Declaración de funciones
void insertarUsuario();
void listarUsuarios();
void enviarSolicitudAmistad();
void gestionarSolicitudesPendientes();
void realizarPublicacion();
void listarPublicaciones();
void volverAlMenuPrincipal();
int es_amigo(Usuario* usuarioactual,Usuario* usuariobuscado);
void agregar_solicitud_pendiente(Usuario* usuariobuscado,Solicitudes* solicitud);
void crear_solicitud_amistad(Usuario* usuarioactual, Usuario* usuariobuscado);



void insertarUsuario() {
    printf("Opción 'Insertar un nuevo usuario' seleccionada.\n");
    Usuario data;
    data = llenarDatosUsuario(usuario);
    addUsuario(head, data);
}

void listarUsuarios() {
    printf("Opción 'Listar todos los usuarios existentes' seleccionada.\n");
}


void enviarSolicitudAmistad(Node* listaUsuarios, Node* usuarioActual) {
    printf("Opción 'Enviar solicitudes de amistad' seleccionada.\n");

    // Pedimos al usuario que ingrese el nombre del amigo al que desea enviar la solicitud
    char nombreAmigo[MAX_LENGHT];
    printf("Escriba el nombre del usuario: ");
    scanf("%s", nombreAmigo);

    // Buscamos al usuario en la lista
    Node* nodoAmigo = buscar_usuario(listaUsuarios, nombreAmigo);
    while (nodoAmigo == NULL) {
        printf("Usuario no encontrado, repita el nombre: ");
        scanf("%s", nombreAmigo);
        nodoAmigo = buscar_usuario(listaUsuarios, nombreAmigo);
    }

    // Verificamos que no sean amigos ya los usuarios
    if (es_amigo(usuarioActual, nodoAmigo->data) == TRUE) {
        return; //en caso que ya seas amigo del usuario salimos de esta función
    }

    // Verificamos que no se haya enviado ya una solicitud de amistad a este usuario
    if (solicitud_pendiente(usuarioActual, nodoAmigo->data) == TRUE) {  // solicitud pendiente tamien se tiene ue crea
        printf("Ya ha enviado una solicitud de amistad a este usuario.  :) \n");
        return; //si ya ha enviado una solicitud de amistad se sale
    }

    // Creamos la solicitud de amistad y la agregamos a la lista de solicitudes pendientes del amigo
    SolicitudAmistad* solicitud = crear_solicitud_amistad(usuarioActual, nodoAmigo->data);
    agregar_solicitud_pendiente(nodoAmigo->data, solicitud);
    printf("Solicitud de amistad enviada a %s.\n", nodoAmigo->data->nombreUsuario);

}



i es_amigo(Usuario* usuarioactual,Usuario* usuariobuscado){
    if (buscar_usuario(usuarioactual, usuariobuscado->nombreUsuario) == NULL){
        printf("Este ususario y tu ya sois amigos");
        return TRUE;
    }
    else return FALSE;
}

void solicitud_pendiente(Usuario* usuarioactual,Usuario* usuariobuscado){

}

void crear_solicitud_amistad(Usuario* usuarioactual, Usuario* usuariobuscado){

}

void agregar_solicitud_pendiente(Usuario* usuariobuscado,Solicitudes* solicitud){

}

void gestionarSolicitudesPendientes() {
    printf("Opción 'Gestionar las solicitudes pendientes' seleccionada.\n");

}

void realizarPublicacion() {
    printf("Opción 'Realizar una publicación' seleccionada.\n");

}

void listarPublicaciones() {
    printf("Opción 'Listar las publicaciones del usuario seleccionado' seleccionada.\n");

}

void volverAlMenuPrincipal() {
    printf("Volviendo al menú principal...\n");
    mostrarMenuPrincipal();
}
