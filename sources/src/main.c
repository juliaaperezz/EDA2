#include <stdio.h>

#include "../headers/usuario.h"
#include "../headers/funciones_menu.h"
#include "../headers/user_linked.h"
#include "../src/usuario.c"

void mostrarMenuPrincipal();

// Función principal
int main() {

    struct Node* head = NULL;

    // Cargar usuarios desde el archivo
    cargarUsuariosDesdeArchivo(&head, "InfUsuarios.txt");

    // Imprimir la lista de usuarios
    listarUsuarios(head);

    mostrarMenuPrincipal();
    return 0;
}

