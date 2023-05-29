#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones_menu.h"
#include "../headers/menu.h"
#include "../headers/usuario.h"
#include "../headers/user_linked.h"


// (Interfaz usuario)
// Declaración de funciones
void llenarDatosUsuario(struct Node* head);
void mostrarDatosUsuario(Usuario *usuario);
struct Node* buscarUsuario(struct Node *head, char *nombreUsuario);
void cargar_usuarios (struct Node* head);



// menú que no hará falta
/*
int menu_interfaz_usuario() {  //
    Usuario usuarios[MAX_USUARIOS];
    int numUsuarios = 0;

    int opcion;

    do {
        printf("=== Interfaz ===\n");
        printf("1. Agregar usuario\n");
        printf("2. Mostrar usuarios\n");
        printf("3. Buscar usuario\n");
        printf("4. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (numUsuarios < MAX_USUARIOS) {
                    llenarDatosUsuario(&usuarios[numUsuarios]);
                    numUsuarios++;
                    printf("Usuario agregado correctamente.\n");
                } else {
                    printf("No se pueden agregar más usuarios. Límite alcanzado.\n");
                }
                break;
            case 2:
                printf("=== Usuarios registrados ===\n");
                for (int i = 0; i < numUsuarios; i++) {
                    mostrarDatosUsuario(&usuarios[i]);
                    printf("\n");
                }
                break;
            case 3:
                printf("Ingrese el nombre de usuario: ");
                char nombreUsuario[100];
                scanf("%s", nombreUsuario);
                Usuario* usuario =
                if (usuario != NULL) {
                    mostrarDatosUsuario(usuario);
                } else {
                    printf("Usuario no encontrado.\n");
                }
                break;
            case 4:
                printf("Terminando ejecución...\n");
                break;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}*/

void menuUsuario(struct Node *usuario) {
    int opcion;

    do {
        printf("=== Menu Usuario ===\n");
        printf("1. Enviar solicitudes de amistad\n");
        printf("2. Gestionar las solicitudes pendientes\n");
        printf("3. Realizar una publicacion\n");
        printf("4. Listar las publicaciones del usuario seleccionado\n");
        printf("5. Cerrar sesión\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1){
            //enviarSolicitudAmistad();

        }else if (opcion == 2){
            //gestionarSolicitudesPendientes();

        }else if (opcion == 3){
            //realizarPublicacion();

        }else if (opcion == 4){
            //listarPublicaciones();

        }else if (opcion == 5){
            printf("Cerrando sesion y volviendo al menu principal...\n");
        }
        else
            printf("Opción invalida. Por favor, ingrese una opción valida.\n");
    } while (opcion != 5);
}

// Función para llenar los datos de un usuario
void llenarDatosUsuario(struct Node* head) {

    Usuario* useradd = malloc(sizeof(Usuario)); // Reservar memoria para el usuario

    printf("Ingrese el nombre de usuario: ");
    scanf("%s", useradd->nombreUsuario);
   // if (buscarUsuario(head, usuario->nombreUsuario) != NULL) {
  //      printf("El nombre de usuario ya existe. Por favor, ingrese otro nombre de usuario.\n");
  //      return NULL;
   // }
    printf("Ingrese su edad: ");
    scanf("%d", &(useradd->edad));

    printf("Ingrese su dirección de correo electrónico: ");
    scanf("%s", useradd->correoElectronico);

    printf("Ingrese su ubicación: ");
    scanf("%s", useradd->ubicacion);

    printf("De la siguiente lista ingrese sus 5 gustos o preferencias:\n");
    printf("(escriba el número asociado a su preferencia y pulse enter)\n");
    printf("[1- Música clásica \n2- Jazz \n3- Rock \n4- Pop \n5- Rap \n6- Reggae\n7- Reggaeton\n8- Dembow\n9- Techno\n10- Trap\n");
    printf("11- Libros de Aventura\n12- Libros de Ciencia-Ficción\n13- Libros de Romance\n14- Libros Policíaco\n15- Libros de Terror\n16- Libros de Humor\n17- Libros de Poesía\n18- Libros de Fantasía\n19- Libros de Teatro\n20- Libros de Historia]\n");

    for (int i = 0; i < 5; i++) {
        scanf("%d", &(useradd->gustos[i]));
    }

    printf("El usuario a agregar: \n");
    printf(" Nombre de usuario: %s\n", useradd->nombreUsuario);
    printf(" Edad: %d\n", useradd->edad);
    printf(" Correo electrónico: %s\n", useradd->correoElectronico);
    printf(" Ubicación: %s\n", useradd->ubicacion);
    printf(" Gustos o preferencias:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", useradd->gustos[i]);
    }
    printf("DEBUG: llenarDatosUsuario: addUsuario\n");
    addUsuario(&head, useradd);

}

// Función para mostrar los datos de un usuario
void mostrarDatosUsuario(Usuario* usuario) {
    printf("Nombre de usuario: %s\n", usuario->nombreUsuario);
    printf("Edad: %d\n", usuario->edad);
    printf("Correo electrónico: %s\n", usuario->correoElectronico);
    printf("Ubicación: %s\n", usuario->ubicacion);
    printf("Gustos o preferencias:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", usuario->gustos[i]);
    }
}


// Función para buscar una persona por su usuario
struct Node* buscarUsuario(struct Node *head, char *nombreUsuario){
    if (head == NULL) { // donde esta definido node C or H
        return NULL; // Empty linked list
    }//head is a list containing the data of all the user, true? yes, mira en user_linked,c

    struct Node* current = head;
    while (current != NULL) {
        if (strcmp(current->data.nombreUsuario, nombreUsuario) == 0) {
            return current; // User found (case-insensitive match)
        }
        current = current->next;

    }
    return NULL; // User not found
}

/*
void cargar_usuarios (struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf ("Nombre del Usuario/a : %s\n", current->data.nombreUsuario);
        printf ("Edad : %d\n", current->data.edad);
        printf ("Correo electrónico : %s\n", current->data.correoElectronico);
        printf ("Ubicación : %s\n", current->data.ubicacion);
        printf ("Gustos : %s\n", current->data.gustos);

        for (int i = 0; i < MAX_INTERESTS, i++) {
            printf (" - %s", current -> data.gustos[i]);
        }
        printf ("\n");
        current = current->next;
    }
}
*/
