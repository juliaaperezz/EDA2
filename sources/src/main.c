
#include <stdio.h>

#include "../headers/usuario.h"
#include "../headers/menu.h"
#include "../headers/funciones submenu.h"

void mostrarMenuPrincipal();
void cargarUsuariosDesdeArchivo(Node** lista, char* nombreArchivo);


// Función principal
int main() {
    printf("Bienvenido a BookTune! :)\n");
    // creamos lista de usuarios
    struct Node* listaUsuarios = NULL;
    //cargar archivo
    cargarUsuariosDesdeArchivo(&listaUsuarios, "usuarios.csv");

    //mostramos el menú
    mostrarMenuPrincipal();
    return 0;
}
