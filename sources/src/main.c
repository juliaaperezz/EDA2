
#include <stdio.h>

#include "../headers/menu.h"
#include "../headers/usuario.h"
#include "../headers/funciones submenu.h"
#include "../headers/main.h"

void mostrarMenuPrincipal(); // funcion: ?
void cargarUsuariosDesdeArchivo(Node** lista, char* nombreArchivo);


// Función principal
int main() {
    printf("Bienvenido a BookTune! :)\n");
    // creamos lista de usuarios

    //struct Node* listaUsuarios = NULL;

    //mostramos el menú
    mostrarMenuPrincipal();
    // faltaba pasar la lista para que se pueda modificar (agregar listaUsuarios como argumento)
    return 0;
}
