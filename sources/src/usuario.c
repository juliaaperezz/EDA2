#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones_menu.h"
#include "../headers/menu.h"
#include "../headers/usuario.h"

// (Interfaz usuario)
// Declaración de funciones
Usuario* llenarDatosUsuario();
void mostrarDatosUsuario(Usuario *usuario);
struct Node* buscar_usuario(struct Node *head, char *nombreUsuario);
void cargar_usuarios (struct Node* head);


// menú que no hará falta

int menu_interfaz_usuario() {
    Usuario usuarios[MAX_USUARIOS];
    int numUsuarios = 0;
    int opcion;

    do {
        printf("=== Interfaz ===\n");
        printf("1. Agregar usuario\n");
        printf("2. Mostrar usuarios\n");
        printf("3. Salir\n");
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
                printf("Terminando ejecución...\n");
                break;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}

// Función para llenar los datos de un usuario
Usuario* llenarDatosUsuario() {

    Usuario* usuario;

    printf("Ingrese el nombre de usuario: ");
    scanf("%s", usuario->nombreUsuario);

    printf("Ingrese su edad: ");
    scanf("%d", &(usuario->edad));

    printf("Ingrese su dirección de correo electrónico: ");
    scanf("%s", usuario->correoElectronico);

    printf("Ingrese su ubicación: ");
    scanf("%s", usuario->ubicacion);

    printf("De la siguiente lista ingrese sus 5 gustos o preferencias:\n");
    printf("(escriba el número asociado a su preferencia y pulse enter)\n");
    printf("[1- Música clásica \n2- Jazz \n3- Rock \n4- Pop \n5- Rap \n6- Reggae\n7- Reggaeton\n8- Dembow\n9- Techno\n10- Trap\n");
    printf("11- Libros de Aventura\n12- Libros de Ciencia-Ficción\n13- Libros de Romance\n14- Libros Policíaco\n15- Libros de Terror\n16- Libros de Humor\n17- Libros de Poesía\n18- Libros de Fantasía\n19- Libros de Teatro\n20- Libros de Historia]\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", usuario->gustos[i]);
    }

    return usuario;

}

// Función para mostrar los datos de un usuario
void mostrarDatosUsuario(Usuario* usuario) {
    printf("Nombre de usuario: %s\n", usuario->nombreUsuario);
    printf("Edad: %d\n", usuario->edad);
    printf("Correo electrónico: %s\n", usuario->correoElectronico);
    printf("Ubicación: %s\n", usuario->ubicacion);
    printf("Gustos o preferencias:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", usuario->gustos[i]);
    }
}
/*

// Función para buscar una persona por su usuario
struct Node* buscar_usuario(struct Node *head, char *nombreUsuario) {
    struct Node *current = head;
    while (current != NULL) {
        if (strcmp(current->data.nombreUsuario, nombreUsuario) == 0) {
            return current; // Se encontró el usuario
        }
        current = current->next;
    }
    return NULL; // No se encontró el usuario
}

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
