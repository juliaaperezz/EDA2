#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones_menu.h"
#include "../headers/menu.h"
#include "../headers/usuario.h"
#include "../headers/user_linked.h"


// (Interfaz usuario)
// Declaración de funciones
void menuUsuario(struct Node *usuario);
void llenarDatosUsuario(struct Node* head);
struct Node* buscarUsuario(struct Node *head, char *nombreUsuario);
void cargarUsuariosDesdeArchivo(struct Node** head, const char* nombreArchivo);


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
    if (buscarUsuario(head, usuario->nombreusuario) != NULL) {
        printf("El nombre de usuario ya existe. Por favor, ingrese otro nombre de usuario.\n");
    }
        return NULL;

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
void mostrarDatosUsuario(Usuario* usuario){
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

void cargarUsuariosDesdeArchivo(struct Node** head, const char* nombreArchivo){
    FILE* archivo = fopen("InfUsuarios.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char buffer[MAX_LENGTH];
    while (fgets(buffer, sizeof(buffer), archivo)) {
        // Eliminar el carácter de nueva línea del final
        buffer[strcspn(buffer, "\n")] = '\0';

        Usuario usuario;

        // Leer los datos del usuario desde el archivo
        strncpy(usuario.nombreUsuario, buffer, MAX_LENGTH);
        fgets(buffer, sizeof(buffer), archivo);
        usuario.edad = atoi(buffer);
        fgets(usuario.correoElectronico, sizeof(usuario.correoElectronico), archivo);
        fgets(usuario.ubicacion, sizeof(usuario.ubicacion), archivo);
        for (int i = 0; i < MAX_INTERESTS; i++) {
            fgets(buffer, sizeof(buffer), archivo);
            usuario.gustos[i] = atoi(buffer);
        }

        // Agregar el usuario a la lista
        addUsuario(head, &usuario);
    }

    fclose(archivo);
}
