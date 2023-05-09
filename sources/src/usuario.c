//
// Created by julia on 09/05/2023.
//

#include "../headers/usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones_menu.h"
#include "../headers/menu.h"
#include "menu.c"
#include "main.c"

// (Interfaz usuario)
// Declaración de funciones
void llenarDatosUsuario(Usuario* usuario);
void mostrarDatosUsuario(Usuario *usuario);

int main() {
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
                    mostrarDatosUsuario(usuarios[i]);
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
void llenarDatosUsuario(Usuario* usuario) {
    printf("Ingrese el nombre de usuario: ");
    scanf("%s", usuario->nombreUsuario);

    printf("Ingrese la edad: ");
    scanf("%d", &(usuario->edad));

    printf("Ingrese la dirección de correo electrónico: ");
    scanf("%s", usuario->correoElectronico);

    printf("Ingrese la ubicación: ");
    scanf("%s", usuario->ubicacion);

    printf("Ingrese 5 gustos o preferencias separados por espacios:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%s", usuario->gustos[i]);
    }
}

// Función para mostrar los datos de un usuario
void mostrarDatosUsuario(Usuario usuario) {
    printf("Nombre de usuario: %s\n", usuario.nombreUsuario);
    printf("Edad: %d\n", usuario.edad);
    printf("Correo electrónico: %s\n", usuario.correoElectronico);
    printf("Ubicación: %s\n", usuario.ubicacion);
    printf("Gustos o preferencias:\n");
    for (int i = 0; i < 5; i++) {
        printf("- %s\n", usuario.gustos[i]);
    }
}

