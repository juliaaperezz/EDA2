//
// Created by julia on 09/05/2023.
//

#include "../headers/funciones_menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "usuario.c"
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


void insertarUsuario() {
    printf("Opción 'Insertar un nuevo usuario' seleccionada.\n");
    llenarDatosUsuario(Usuario* Usuario);
}

void listarUsuarios() {
    printf("Opción 'Listar todos los usuarios existentes' seleccionada.\n");

}


void enviarSolicitudAmistad() {
    printf("Opción 'Enviar solicitudes de amistad' seleccionada.\n");

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
