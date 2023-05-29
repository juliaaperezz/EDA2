#include <stdio.h>
#include "../headers/main.h"
#include "../headers/funciones_menu.h"
#include "../headers/usuario.h"

#include <locale.h>   //para que se imprima bien los strings ue contienen acentos, etc.
#include <stdlib.h>
// Declaración de variables globales

struct Node head;
// Declaración de funciones
void mostrarMenuPrincipal();
void menuUsuario();
void llenarDatosUsuario(struct Node *head);


// Función que muestra el menú principal
void mostrarMenuPrincipal() {
    setlocale(LC_ALL, "es_ES");   //para se impriman los acentos al ejecutar el programa  (no funciona)

    int opcion;

    do { // cambiar esto por un switch, que? ahora mismo es un if-elseif
       printf("=== Menu Principal ===\n");
        printf("1. Insertar un nuevo usuario\n");
        printf("2. Listar todos los usuarios existentes\n");
        printf("3. Operar como un usuario especifico\n");
        printf("4. Salir \n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1){
            //insertarUsuario();
            llenarDatosUsuario(&head);
        }

        else if (opcion == 2){
            //listarUsuarios();
            mostrarMenuPrincipal();
        }

        else if (opcion == 3){
            char usuario[20];
            printf("Que usuario desea utilizar?\n");
            printf("Usuario: ");
            scanf("%s", usuario);
            struct Node *user = buscarUsuario(&head, usuario);
            if (user == NULL){
                printf("El usuario no existe.\n");
            }
            else {
                menuUsuario(&user);
                //mostrarMenuPrincipal();
            }
    }
        else if (opcion == 4)
            printf("Saliendo...\n");
        else
            printf("Opcion invalida. Por favor, ingrese una opcion valida.\n");
    } while (opcion != 4);
}

//Función que muestra el menú del usuario
 // moved to usuario.c
