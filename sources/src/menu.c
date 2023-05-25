#include <stdio.h>
#include "../headers/main.h"
#include "../headers/funciones_menu.h"
#include "../headers/usuario.h"

#include <locale.h>   //para que se imprima bien los strings ue contienen acentos, etc.

// Declaración de funciones
void mostrarMenuPrincipal();
void menuUsuario();


// Función que muestra el menú principal
void mostrarMenuPrincipal() {
    setlocale(LC_ALL, "es_ES"); int opcion;  //para se impriman los acentos al ejecutar el programa

    do {
       printf("=== Menú Principal ===\n");
        printf("1. Insertar un nuevo usuario\n");
        printf("2. Listar todos los usuarios existentes\n");
        printf("3. Operar como un usuario específico\n");
        printf("4. Salir \n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        if (opcion == 1){
            //insertarUsuario();
            mostrarMenuPrincipal();
        }

        else if (opcion == 2){
            //listarUsuarios();
            mostrarMenuPrincipal();
        }

        else if (opcion == 3){
            //menuUsuario();
            mostrarMenuPrincipal();
        }
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

        if (opcion == 1){
            //enviarSolicitudAmistad();
            menuUsuario();
        }else if (opcion == 2){
            //gestionarSolicitudesPendientes();
            menuUsuario();
        }else if (opcion == 3){
            //realizarPublicacion();
            menuUsuario();
        }else if (opcion == 4){
            //listarPublicaciones();
            menuUsuario();
        }else if (opcion == 5){
            mostrarMenuPrincipal();
        }
        else
            printf("Opción inválida. Por favor, ingrese una opción válida.\n");
    } while (opcion != 5);
}
