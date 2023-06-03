#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/menu.h"
#include "../headers/usuario.h"
#include "../headers/funciones submenu.h"
#include "../headers/main.h"


//para primera opción menú
void llenarDatosUsuario(Usuario* usuario);  // CORRECTA
void limpiarBufferEntrada();
void agregarUsuario(Node** lista,  Usuario usuario);  //CORRECTA

//para segunda opción del menú
void listarUsuarios(Node* lista);

//para tercera opción del menú
Usuario* buscarUsuario(Node* lista, char* nombreUsuario);


//para la quarta opción del menú
void cargarUsuariosDesdeArchivo(Node** lista, char* nombreArchivo);




void mostrarDatosUsuario(Usuario *usuario);




// PRIMERA OPCIÓN DEL MENÚ: insertar nuevo usuario

    // Función para llenar los datos de un usuario
void llenarDatosUsuario(Usuario* usuario) {
    char temp1[MAX_LENGHT];
    int temp2;

    printf("Ingrese el nombre de usuario: ");
    //scanf("%c",&temp1);
    scanf("%[^\n]", temp1);  // %[^\n] para poder leer una string con espacios
    //&usuario->nombreUsuario = temp1;


    printf("\nIngrese su edad: ");
    scanf("%d", usuario->edad);

    printf("\nIngrese su direccion de correo electronico: ");
    scanf("%[^\n]", &usuario->correoElectronico);

    printf("\nIngrese su ubicacion: ");
    scanf("%[^\n]", &usuario->ubicacion);

    printf("\nIngrese sus 5 gustos o preferencias:");
    for (int i = 0; i < 5; i++) {
        printf("\nGusto %d :", i+1);
        scanf("%[^\n]", &usuario->gustos[i]);
    }

}


    //estructura node en headers
    // Función que agrega los nuevos usuarios a la lista dinamica
void agregarUsuario(Node** lista, Usuario usuario) {
    //reservamos más memoria
    Node* nuevoNodo = (Node*)malloc(sizeof(Node));
    nuevoNodo->usuario = usuario;
    //nuevoNodo sera el siguiente en la lista
    nuevoNodo->next = *lista;
    *lista = nuevoNodo;
}



//SEGUNDA OPCIÓN DEL MENÚ: listar usuarios existentes

    // Función lista los usuarios existentes
void listarUsuarios(Node* lista) {
    printf("Usuarios registrados:\n");
    Node* actual = lista;
    while (actual != NULL) {
        printf("Nombre: %s\n", actual->usuario.nombreUsuario);
        printf("Edad: %d\n", actual->usuario.edad);
        printf("Correo: %s\n", actual->usuario.correoElectronico);
        printf("Ubicacion: %s\n", actual->usuario.ubicacion);
        printf("Gustos o preferencias:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. %s\n", i + 1, actual->usuario.gustos[i]);
        }
        printf("\n");

        actual = actual->next;
    }
}


//TERCERA OPCIÓN DEL MENÚ: operar como usuario específico

    // Función para buscar un usuario utilizando un algoritmo de búsqueda
Usuario* buscarUsuario(Node* lista, char* nombreUsuario) {
    Node* actual = lista;
    while (actual != NULL) {
        if (strcmp(actual->usuario.nombreUsuario, nombreUsuario) == 0) {
            return &(actual->usuario);
        }
        actual = actual->next;
    }
    return NULL;
}

//(faltan funciones submenú)




//CUARTA OPCIÓN DEL MENÚ: cargar datos usuarios desde CSV

// falta acabar de comentar
void cargarUsuariosDesdeArchivo(Node** lista, char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char linea[MAX_LENGHT*4];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {

        //crea un usuario para cada linia del archivo
        Usuario nuevoUsuario;
        sscanf(linea, "%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
               nuevoUsuario.nombreUsuario, &(nuevoUsuario.edad), nuevoUsuario.correoElectronico, nuevoUsuario.ubicacion,
               nuevoUsuario.gustos[0], nuevoUsuario.gustos[1], nuevoUsuario.gustos[2],
               nuevoUsuario.gustos[3], nuevoUsuario.gustos[4]);
        //va registrando cada nuevo usuario que crea
        agregarUsuario(lista, nuevoUsuario);
    }
    // cerramos el archivo
    fclose(archivo);
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
        if (strcmp(current->usuario.nombreUsuario, nombreUsuario) == 0) {
            return current; // Se encontró el usuario
        }
        current = current->next;
    }
    return NULL; // No se encontró el usuario
}

void cargar_usuarios (struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf ("Nombre del Usuario/a : %s\n", current->usuario.nombreUsuario);
        printf ("Edad : %d\n", current->usuario.edad);
        printf ("Correo electrónico : %s\n", current->usuario.correoElectronico);
        printf ("Ubicación : %s\n", current->usuario.ubicacion);
        printf ("Gustos : %s\n", current->usuario.gustos);

        for (int i = 0; i < MAX_INTERESTS, i++) {
            printf (" - %s", current -> usuario.gustos[i]);
        }
        printf ("\n");
        current = current->next;
    }
}
*/
