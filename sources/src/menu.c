//
// Created by julia on 09/05/2023.
//

#include "../headers/menu.h"

//
// Created by julia on 09/05/2023.
//

#include <stdio.h>
#include "funciones_menu.c"
#include "../headers/funciones_menu.h"
#include "usuario.c"
#include "../headers/usuario.h"

// Declaración de funciones
void mostrarMenuPrincipal();
void menuUsuario();



// Función que muestra el menú principal
void mostrarMenuPrincipal() {
    int opcion;

    do {
        printf("=== Menú Principal ===\n");
        printf("1. Insertar un nuevo usuario\n");
        printf("2. Listar todos los usuarios existentes\n");
        printf("3. Operar como un usuario específico\n");
        printf("4. Salir \n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        if (opcion == 1)
            insertarUsuario();
        else if (opcion == 2)
            listarUsuarios();
        else if (opcion == 3)
            menuUsuario();
        else if (opcion == 4)
            printf("Saliendo...\n");
        else
            printf("Opción inválida. Por favor, ingrese una opción válida.\n");
    } while (opcion != 4);
}



//Función que muestra el menú del usuario
void menuUsuario() {
    int opcion;

    do {
        printf("=== Menú Usuario ===\n");
        printf("1. Enviar solicitudes de amistad\n");
        printf("2. Gestionar las solicitudes pendientes\n");
        printf("3. Realizar una publicación\n");
        printf("4. Listar las publicaciones del usuario seleccionado\n");
        printf("5. Volver al menú principal\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        if (opcion == 1)
            enviarSolicitudAmistad();
        else if (opcion == 2)
            gestionarSolicitudesPendientes();
        else if (opcion == 3)
            realizarPublicacion();
        else if (opcion == 4)
            listarPublicaciones();
        else if (opcion == 5)
            volverAlMenuPrincipal();
        else
            printf("Opción inválida. Por favor, ingrese una opción válida.\n");
    } while (opcion != 5);
}
