/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/menu.h"
#include "../headers/usuario.h"
#include "../headers/funciones submenu.h"
#include "../headers/main.h"

// Declaración de funciones menú
void mostrarMenuPrincipal();   //CORRECTA
void insertarUsuario(Usuario usuarios[], int *contadorUsuarios);
void listarUsuarios(Usuario usuarios[], int contadorUsuarios);

// Declaración de funciones submenú
void submenuUsuario(Usuario usuarios[], int contadorUsuarios);
void enviarSolicitudAmistad(Usuario usuarios[], int contadorUsuarios, int indiceUsuario);
void gestionarSolicitudesPendientes();
void realizarPublicacion(int indiceUsuario);
void listarPublicaciones(Usuario usuarios[], int contadorUsuarios, int indiceUsuario);

//_____________________________
void agregarUsuario(Node** lista,  Usuario usuario); //CORRECTA
struct Node* listaUsuarios;  //CORRECTA
Usuario* buscarUsuario(Node* lista, char* nombreUsuario);  //CORRECTA
//char nombreUsuarioAmigo[50];

void cargarUsuariosDesdeArchivo(Node** lista, char* nombreArchivo);



// Función que muestra el menú principal
void mostrarMenuPrincipal() {
    Usuario usuarios[100];
    int contadorUsuarios = 0;
    int opcion;

    do {
        printf("\n--- Menú Principal ---\n");
        printf("1. Insertar un nuevo usuario\n");
        printf("2. Listar todos los usuarios existentes\n");
        printf("3. Operar como un usuario específico\n");
        printf("4. Salir (Terminar ejecución)\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                insertarUsuario(usuarios, &contadorUsuarios);
                break;
            case 2:
                listarUsuarios(usuarios, contadorUsuarios);
                break;
            case 3:
                submenuUsuario(usuarios, contadorUsuarios);
                break;
            case 4:
                printf("Terminando ejecución del programa.\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 4);

    //return 0;
}

void submenuUsuario(Usuario usuarios[], int contadorUsuarios) {
    int opcion;
    char nombreUsuario[50];
    printf("Ingrese el nombre del usuario: ");
    scanf("%s", nombreUsuario);

    int indiceUsuario = -1;
    for (int i = 0; i < contadorUsuarios; i++) {
        if (strcmp(nombreUsuario, usuarios[i].nombreUsuario) == 0) {
            indiceUsuario = i;
            break;
        }
    }

    if (indiceUsuario == -1) {
        printf("El usuario no existe.\n");
        return;
    }

    do {
        printf("\n--- Submenú de usuario ---\n");
        printf("1. Enviar solicitud de amistad\n");
        printf("2. Gestionar solicitudes pendientes\n");
        printf("3. Realizar una publicación\n");
        printf("4. Listar las publicaciones del usuario\n");
        printf("5. Volver al menú principal\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Solicitud de amistad enviada.\n");
                enviarSolicitudAmistad(usuarios, contadorUsuarios, indiceUsuario);
                break;
            case 2:
                //gestionarSolicitudesPendientes();
                printf("Solicitudes pendientes gestionadas.\n");
                break;
            case 3:
                realizarPublicacion(indiceUsuario);
                printf("Publicación realizada.\n");
                break;
            case 4:
                printf("Publicaciones del usuario:\n");
                listarPublicaciones(usuarios, contadorUsuarios, indiceUsuario);
                // Aquí puedes implementar la lógica para listar las publicaciones del usuario seleccionado
                break;
            case 5:
                printf("Volviendo al menú principal.\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 5);
}*/
