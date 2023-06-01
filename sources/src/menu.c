#include <stdio.h>
#include "../headers/main.h"
#include "../headers/usuario.h"



// Declaración de funciones
void mostrarMenuPrincipal();   //CORRECTA
void menuUsuario(Usuario* usuario);  //CORRECTA
Usuario* llenarDatosUsuario();   //CORRECTA
void listarUsuarios(Node* lista); //CORRECTA
void agregarUsuario(Node** lista,  Usuario usuario); //CORRECTA
struct Node* listaUsuarios;  //CORRECTA
Usuario* buscarUsuario(Node* lista, char* nombreUsuario);  //CORRECTA
char nombreUsuarioAmigo[50];

void enviarSolicitudAmistad(Node* listaUsuarios, Usuario* usuario, char* nombreUsuarioAmigo);




// Función que muestra el menú principal
void mostrarMenuPrincipal() {
    int opcion;

    do {
       printf("=== Menu Principal ===\n");
        printf("1. Insertar un nuevo usuario\n");
        printf("2. Listar todos los usuarios existentes\n");
        printf("3. Operar como un usuario especifico\n");
        printf("4. Cargar datos usuario desde CSV\n");
        printf("5. Salir \n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                printf("Opcion 'Insertar un nuevo usuario' seleccionada.\n");

                //crea un nuevo usuario
                Usuario nuevoUsuario;
                //le pide los datos
                llenarDatosUsuario(&nuevoUsuario);
                //agrega el usuario a nuestra lista dinamica listaUsuarios
                agregarUsuario(&listaUsuarios, nuevoUsuario);

                // volvemos a mostrar el menú principal
                mostrarMenuPrincipal();
                break;

            case 2:
                printf("Opcion 'Listar todos los usuarios existentes' seleccionada.\n");

                //lista los usuarios existentes
                listarUsuarios(listaUsuarios);
                //volvemos a mostrar el menú principal
                mostrarMenuPrincipal();
                break;

            case 3:
                printf("Opcion 'Operar como un usuario especifico' seleccionada.\n");

                //el usuario se registra
                char nombreUsuario[MAX_LENGHT];
                printf("Ingrese el nombre de usuario: ");
                scanf("%s", nombreUsuario);

                //utilizamos función buscar usuario para saber si existe, en el caso de que no se indicará
                // y se imprime el menu principal otra vez
                Usuario* usuarioEncontrado = buscarUsuario(listaUsuarios, nombreUsuario);
                if (usuarioEncontrado != NULL) {
                    menuUsuario(usuarioEncontrado);
                } else {
                    printf("No se encontro el usuario con el nombre especificado.\n");
                    printf("Porfavor inserte nuevo usuario");
                    mostrarMenuPrincipal();
                }
                break;

            case 4:
                printf("Opcion 'Cargar datos usuario desde CSV' seleccionada.\n");
                break;

            case 5:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida. Por favor, ingrese una opcion valida.\n");
                break;
        }
    } while (opcion != 5);
}



//Función que muestra el menú del usuario
void menuUsuario(Usuario* usuario) {
    int opcion;

    do {
        printf("=== Menu Usuario ===\n");
        printf("1. Enviar solicitudes de amistad\n");
        printf("2. Gestionar las solicitudes pendientes\n");
        printf("3. Realizar una publicacion\n");
        printf("4. Listar las publicaciones del usuario seleccionado\n");
        printf("5. Volver al menu principal\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:
                char nombreUsuarioAmigo[MAX_LENGHT];
                printf("Ingrese el nombre de usuario del amigo: ");
                scanf("%s", nombreUsuarioAmigo);

                enviarSolicitudAmistad(listaUsuarios, usuario, nombreUsuarioAmigo);
                menuUsuario(usuario);
                break;

            case 2:
                //gestionarSolicitudesPendientes();
                menuUsuario(usuario);
                break;

            case 3:
                //realizarPublicacion();
                menuUsuario(usuario);
                break;

            case 4:
                //listarPublicaciones();
                menuUsuario(usuario);
                break;
            case 5:
                mostrarMenuPrincipal();
                break;

            default:
                printf("Opcion invalida. Por favor, ingrese una opcion valida.\n");
                break;
        }
    } while (opcion != 5);
}