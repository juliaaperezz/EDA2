#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <regex.h>
#include <ctype.h>
#include "../headers/menu.h"
#include "../headers/usuario.h"
#include "../headers/funciones submenu.h"
#include "../headers/main.h"


//para primera opción menú
int validarEdad(const char *edad);
int validarCorreo(const char *correo);
void insertarUsuario(Usuario usuarios[], int *contadorUsuarios);

//para segunda opción del menú
void listarUsuarios(struct Node *lista);
int contarUsuarios(struct Node *lista);
//para tercera opción del menú
void submenuUsuario(Usuario usuarios[], int contadorUsuarios);

void enviarSolicitudAmistad(Usuario usuarios[], int contadorUsuarios, int indiceUsuario);
void gestionarSolicitudesPendientes();
void realizarPublicacion(int indiceUsuario);
void listarPublicaciones(Usuario usuarios[], int contadorUsuarios, int indiceUsuario);

//para la quarta opción del menú

//_____________
void agregarUsuario(Node** lista,  Usuario usuario);  //CORRECTA


//para tercera opción del menú
Usuario* buscarUsuario(Node* lista, char* nombreUsuario);


//Comprueba que dato introducido por el usuario en edad sea un número entero
int validarEdad(const char *edad) {
    for (int i = 0; i < strlen(edad); i++) {
        if (!isdigit(edad[i])) {
            return 0;  // La edad no es un número entero
        }
    }
    return 1;  // La edad es un número entero
}

//Comprueba que dato introducido por el usuario en correo electrónico sea uno válido

int validarCorreo(const char *correo) {
    int i, arroba = 0, punto = 0;
    int longitud = strlen(correo);

    // Verificar si el correo tiene al menos un caracter antes de la arroba
    if (correo[0] == '@' || correo[longitud - 1] == '@') {
        return 0;
    }
    // Verificar si hay exactamente un caracter '@' y al menos un caracter '.' después de la arroba
    for (i = 0; i < longitud; i++) {
        if (correo[i] == '@') {
            arroba++;
        } else if (correo[i] == '.') {
            punto++;
        }
    }
    if (arroba != 1 || punto == 0 || punto == longitud - 1) {
        return 0;
    }
    // Verificar que no haya dos puntos consecutivos
    for (i = 0; i < longitud - 1; i++) {
        if (correo[i] == '.' && correo[i + 1] == '.') {
            return 0;
        }
    }
    return 1;  // El correo tiene un formato básico válido
}


// PRIMERA OPCIÓN DEL MENÚ: insertar nuevo usuario

// Función para llenar los datos de un usuario
void insertarUsuario(Usuario usuarios[], int *contadorUsuarios) {
    printf("Ingrese el nombre del usuario: ");
    scanf("%s", usuarios[*contadorUsuarios].nombreUsuario);

    char edad[50];
    do {
        printf("Ingrese la edad del usuario: ");
        scanf("%s", edad);
        if (!validarEdad(edad)) {
            printf("La edad no es un número entero. Intente nuevamente.\n");
        }
    } while (!validarEdad(edad));
    usuarios[*contadorUsuarios].edad = atoi(edad);   // ASCII to integer

    // Validación del correo electrónico
    char correo[50];
    do {
        printf("Ingrese la dirección de correo electrónico del usuario: ");
        scanf("%s", correo);
        if (!validarCorreo(correo)) {
            printf("El correo electrónico no es válido. Intente nuevamente.\n");
        }
    } while (!validarCorreo(correo));
    strcpy(usuarios[*contadorUsuarios].correoElectronico, correo);


    printf("Ingrese la ubicación actual del usuario: ");
    scanf("%s", usuarios[*contadorUsuarios].ubicacion);
    printf("Ingrese 5 gustos o preferencias separados por espacios:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%s", usuarios[*contadorUsuarios].gustos[i]);
    }
    if (*contadorUsuarios < MAX_USUARIOS) {
        (*contadorUsuarios)++;
        printf("Usuario insertado correctamente.\n");
    } else {
        printf("No se puede insertar más usuarios. El arreglo está lleno.\n");
    }
}


//estructura node en headers
// Función que agrega los nuevos usuarios a la lista dinámica
void agregarUsuario(Node** lista, Usuario usuario) {
    // Reservar memoria para el nuevo nodo
    Node* nuevoNodo = (Node*)malloc(sizeof(Node));
    nuevoNodo->usuario = usuario;
    // El nuevo nodo será el siguiente en la lista
    nuevoNodo->next = *lista;
    *lista = nuevoNodo;
}

//SEGUNDA OPCIÓN DEL MENÚ: listar usuarios existentes

// Función lista los usuarios existentes
void listarUsuarios(Node* lista) {
    if (lista == NULL) {
        printf("No hay usuarios registrados.\n");
    } else {
        printf("Usuarios existentes:\n");
        while (lista != NULL) {
            Usuario usuario = lista->usuario;
            printf("Nombre: %s, Edad: %d, Correo: %s, Ubicación: %s\n", usuario.nombreUsuario, usuario.edad, usuario.correoElectronico, usuario.ubicacion);
            printf("Gustos o preferencias:\n");
            for (int j = 0; j < 5; j++) {
                printf("%d. %s\n", j+1, usuario.gustos[j]);
            }
            printf("\n");
            lista = lista->next;
        }
    }
}


//TERCERA OPCIÓN DEL MENÚ: operar como usuario específico

void enviarSolicitudAmistad(Usuario usuarios[], int contadorUsuarios, int indiceUsuario) {
    printf("Ingrese el nombre del usuario al que desea enviar la solicitud de amistad: ");
    char nombreAmigo[50];
    scanf("%s", nombreAmigo);

    int indiceAmigo = -1;
    for (int i = 0; i < contadorUsuarios; i++) {
        if (strcmp(nombreAmigo, usuarios[i].nombreUsuario) == 0) {
            indiceAmigo = i;
            break;
        }
    }
    if (indiceAmigo == -1) {
        printf("El usuario al que desea enviar la solicitud de amistad no existe.\n");
    } else {
        printf("Solicitud de amistad enviada a %s.\n", usuarios[indiceAmigo].nombreUsuario);
    }
}


void gestionarSolicitudesPendientes() {
    printf("Gestionando solicitudes pendientes.\n");
    // Aquí puedes implementar la lógica para gestionar las solicitudes de amistad pendientes
}

void realizarPublicacion(int indiceUsuario) {
    printf("Ingrese el texto de la publicación: ");
    char textoPublicacion[100];
    scanf(" %[^\n]s", textoPublicacion);

    printf("Publicación realizada por el usuario %d: %s\n", indiceUsuario, textoPublicacion);
}

void listarPublicaciones(Usuario usuarios[], int contadorUsuarios, int indiceUsuario) {
    printf("Publicaciones del usuario %s:\n", usuarios[indiceUsuario].nombreUsuario);
    // Aquí puedes implementar la lógica para listar las publicaciones del usuario seleccionado
}

Usuario* buscarUsuario(Node* lista, char* nombreUsuario) {
    Node* current = lista;
    while (current != NULL) {
        if (strcmp(current->usuario.nombreUsuario, nombreUsuario) == 0) {
            return &(current->usuario); // Se encontró el usuario
        }
        current = current->next;
    }
    return NULL; // No se encontró el usuario
}


//CUARTA OPCIÓN DEL MENÚ: cargar datos usuarios desde CSV

// Función para cargar datos de usuarios desde un archivo CSV
void cargarUsuariosDesdeArchivo(Node** lista, char* nombreArchivo) {
    // Abrir el archivo en modo lectura
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char linea[MAX_LENGHT * 4];
    // Leer cada línea del archivo
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        // Crear un nuevo usuario para almacenar los datos de la línea
        Usuario nuevoUsuario;

        // Utilizar sscanf para leer los valores separados por comas en la línea
        sscanf(linea, "%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
               nuevoUsuario.nombreUsuario, &(nuevoUsuario.edad), nuevoUsuario.correoElectronico,
               nuevoUsuario.ubicacion, nuevoUsuario.gustos[0], nuevoUsuario.gustos[1],
               nuevoUsuario.gustos[2], nuevoUsuario.gustos[3], nuevoUsuario.gustos[4]);

        // Agregar el nuevo usuario a la lista
        agregarUsuario(lista, nuevoUsuario);
    }
    // Cerrar el archivo
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

