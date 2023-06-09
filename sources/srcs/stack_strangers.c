//
// Created by Carla Núñez Viñas on 9/6/23.
//

#include "../headers/usuarios.h"
#include "../headers/main+menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void sendFriendRequest(User *sender, User *receiver);

//Funcionalidades pila
// Crea una nueva pila y la devuelve
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));  // Asigna memoria para la estructura Stack
    stack->top = NULL;  // Inicializa el puntero top como NULL, indicando una pila vacía
    return stack;
}

// Comprueba si la pila está vacía
int isEmpty(Stack* stack) {
    return stack->top == NULL;  // La pila está vacía si el puntero top es NULL
}

// Inserta un elemento en la parte superior de la pila
void push(Stack* stack, User* item) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Asigna memoria para el nuevo nodo
    newNode->data = item;  // Almacena los datos del item en el nuevo nodo
    newNode->next = stack->top;  // Establece el siguiente del nuevo nodo al nodo actual en la parte superior de la pila
    stack->top = newNode;  // Actualiza el puntero top para que apunte al nuevo nodo, colocándolo en la parte superior de la pila
}

// Elimina y devuelve el elemento en la parte superior de la pila
User* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow.\n");  // Si la pila está vacía, muestra un mensaje de error y devuelve NULL
        return NULL;
    }
    Node* temp = stack->top;  // Almacena el nodo actual en la parte superior de la pila en una variable temporal
    User* item = temp->data;  // Almacena los datos del item en una variable temporal
    stack->top = temp->next;  // Actualiza el puntero top para que apunte al siguiente nodo en la pila, eliminando el nodo actual de la parte superior
    free(temp);  // Libera la memoria del nodo eliminado
    return item;   // Devuelve los datos del item eliminado
}

//Implementación requerida por la siguiente función, para enviar una solicitud de amistad
void sendFriendRequest(User *sender, User *receiver) {
    // Verificar si el receptor ya tiene una solicitud de amistad pendiente del remitente
    for (int i = 0; i < receiver->FriendRequestsList->pendingRequests; i++) {
        if (receiver->FriendRequestsList->friendRequests[i] == sender) {
            printf("Friend request already sent to %s.\n", receiver->username);
            return;
        }
    }

    // Verificar si el remitente ya es amigo del receptor
    for (int i = 0; i < sender->Friends->friendsCount; i++) {
        if (sender->Friends->friends[i] == receiver) {
            printf("You are already friends with %s.\n", receiver->username);
            return;
        }
    }

    // Agregar la solicitud de amistad al receptor
    receiver->FriendRequestsList->friendRequests[receiver->FriendRequestsList->pendingRequests] = sender;
    receiver->FriendRequestsList->pendingRequests++;

    printf("Friend request sent to %s.\n", receiver->username);
}

//Función para conectarse (conocer) a extraños (no amigos)
void connectWithStrangers(UserList* list, User* user) {
    //Inicialización de variables
    int numStrangers = 0;
    User* strangers[MAX_USERS];

    // Seleccionar 3 usuarios aleatorios que no estén en la lista de amigos del usuario y agregarlos a la pila
    for (int i = 0; i < list->count; i++) {
        User* currUser = &list->users[i];
        if (currUser != user) {
            int isFriend = 0;
            // Comprobamos que los usuarios no sean amigos actualmente
            for (int j = 0; j < user->Friends->friendsCount; j++) {
                if (strcmp(currUser->username, user->Friends->friends[j]->username) == 0) {
                    isFriend = 1;
                    break;
                }
            }
            // En caso de que los usuarios no sean ya amigos este se introducira en la lista de extraños del usuario
            if (!isFriend) {
                strangers[numStrangers++] = currUser;
            }
        }
    }

    //En caso que no haya listados más de tres usuarios reconocidos como extraños (no amigos)
    if (numStrangers < 3) {
        printf("Not enough strangers found.\n");
        return;
    }

    // Shuffle the strangers array
    srand(time(NULL));
    for (int i = 0; i < numStrangers - 1; i++) {
        int j = i + rand() / (RAND_MAX / (numStrangers - i) + 1);
        User* temp = strangers[j];
        strangers[j] = strangers[i];
        strangers[i] = temp;
    }

    // Create a stack for the strangers
    Stack* stack = createStack();
    //introduce los extraños en la pila
    for (int i = 0; i < 3; i++) {
        push(stack, strangers[i]);
    }

    // Assign the stack to user's FriendRequestsList struct
    user->FriendRequestsList->stack = stack;

    int count = 1;
    char option;
    // Recorrer la pila y permitir al usuario decidir si desea enviar una solicitud de amistad a cada persona o no
    while (!isEmpty(user->FriendRequestsList->stack)) {
        // Sacamos de la pila el último elemento que ha entrado en esta
        User* stranger = pop(user->FriendRequestsList->stack);
        printf("Stranger %d: %s\n", count, stranger->username);
        printf("Do you want to know more about the users? (y/n) ");
        scanf("%c", &option);
        getchar();
        //En caso de querer conocer los detalles del usuario que envía la solicitud se muestran por pantalla sus datos
        if (option == 'y' || option == 'Y'){
            printf("===== USER DETAILS =====\n");
            printf("Username: %s\n", stranger->username);
            printf("Age: %d\n", stranger->age);
            printf("Email: %s\n", stranger->email);
            printf("Location: %s\n", stranger->location);
            printf("Preferences: ");
            for (int j = 0; j < MAX_PREFERENCES; j++) {
                printf("%s ", stranger->preferences[j]);
            }
            printf("\n=========================\n");
        }
        printf("Do you want to send a friend request to the stranger? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        getchar();
        //En caso de querer enviar una solicitud de amistad
        if (choice == 'y' || choice == 'Y') {
            // Verificar si el amigo ya tiene una solicitud de amistad pendiente
            int requestSent = 0;
            for (int i = 0; i < stranger->FriendRequestsList->pendingRequests; i++) {
                // Comprueba si el usuario ya ha enviado una solicitud de amistad al extraño
                if (strcmp(stranger->FriendRequestsList->friendRequests[i]->username, user->username) == 0) {
                    printf("Friend request already sent to user %s.\n", stranger->username);
                    requestSent = 1;
                    break;
                }
            }
            //En caso que no se haya enviado una solicitud de amistad previamente
            if (!requestSent) {
                // Enviar solicitud de amistad al extraño
                sendFriendRequest(user, stranger);
                printf("-------------------------\n");
                stranger->FriendRequestsList->friendRequests[stranger->FriendRequestsList->pendingRequests++] = user;
            }
        }
        count++;
    }
    //Libera la memoria de la pila
    free(stack);
}


// Función para añadir un amigo desconocido con gustos coincidentes con una lista dinámica
void addUnknownFriend(User *user, UserList *userList) {

    // Crear una lista temporal para almacenar los usuarios disponibles
    User *availableUsers[MAX_USERS];
    char commonpreference[MAX_NAME_LENGTH];
    int common = 0;
    int availableCount = 0;

    // Generar una semilla aleatoria para la función rand()
    //srand(time(NULL));

    // Obtener 3 usuarios al azar que no estén en la lista de amigos del usuario actual
    while (availableCount < 3) {
        int randomIndex = rand() % userList->count;
        User *randomUser = &userList->users[randomIndex];

        // Comprueba si el usuario aleatorio no está en la lista de amigos del usuario actual
        int isFriend = 0;
        for (int i = 0; i < user->Friends->friendsCount; i++) {
            if (user->Friends->friends[i] == randomUser) {
                isFriend = 1;
                break;
            }
        }

        // Comprueba si el usuario aleatorio no está en la lista temporal de usuarios disponibles (para no mostrar dos usuarios iguales)
        int isAvailable = 0;
        for (int i = 0; i < availableCount; i++) {
            if (availableUsers[i] == randomUser) {
                isAvailable = 1;
                break;
            }
        }

        // Comprueba si el usuario aleatorio tiene una preferencia en común con el usuario actual
        int hasCommonPreference = 0;
        int index = 0;
        for (int i = 0; i < MAX_PREFERENCES; i++) {
            for (int j = 0; j < MAX_PREFERENCES; j++) {
                if (strcmp(user->preferences[i], randomUser->preferences[j]) == 0) {
                    commonpreference[index] = *user->preferences[i]; //almacenamos la primera preferencia en común
                    hasCommonPreference = 1;
                    index++;
                    break;
                }
            }
            if (hasCommonPreference)
                break;
            common++;
        }

        // Si cumple todas las condiciones, se añade a la lista temporal de usuarios disponibles
        if (!isFriend && !isAvailable && hasCommonPreference && randomUser != user) {
            availableUsers[availableCount] = randomUser;
            availableCount++;
        }
    }

    // Mostrar los usuarios disponibles al usuario actual
    printf("Available users:\n");
    for (int i = 0; i < availableCount; i++) {
        printf("%d. %s\n", i + 1, availableUsers[i]->username);
    }

    char option;
    printf("Do you want to know more about the users? (y/n) ");
    scanf("%c", &option);
    getchar();
    //En caso de querer conocer los detalles del usuario que envía la solicitud se muestran por pantalla sus datos
    if (option == 'y' || option == 'Y'){
        printf("===== USERS DETAILS =====\n");
        for(int i = 0; i < availableCount; i++){
            printf("Username: %s\n", availableUsers[i]->username);
            printf("Age: %d\n", availableUsers[i]->age);
            printf("Email: %s\n", availableUsers[i]->email);
            printf("Location: %s\n", availableUsers[i]->location);
            printf("Preferences: ");
            for (int j = 0; j < MAX_PREFERENCES; j++) {
                printf("%s ", availableUsers[i]->preferences[j]);
            }
            if(i == availableCount - 1){
                break;
            }
            printf("-------------------------\n");
        }
        printf("=========================\n");
    }

    // Recorrer hasta que se termine o el usuario decida terminar
    int currentIndex = 0;
    int finished = 0;

    while (!finished) {
        printf("\n¿Do you want to send a friend request to %s? (y/n)\n", availableUsers[currentIndex]->username);
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'y': // En caso de querer agregar como amigo
                if (user->Friends->friendsCount >= MAX_USERS) {
                    printf("You already have the maximum number of friends allowed.\n");
                } else {
                    // Verificar si el amigo ya tiene una solicitud de amistad pendiente
                    int requestSent = 0;
                    for (int i = 0; i < availableUsers[currentIndex]->FriendRequestsList->pendingRequests; i++) {
                        if (strcmp(availableUsers[currentIndex]->FriendRequestsList->friendRequests[i]->username, user->username) == 0) {
                            printf("Friend request already sent to user %s.\n", availableUsers[currentIndex]->username);
                            requestSent = 1;
                            break;
                        }
                    }
                    //En caso que no se haya enviado una solicitud de amistad previamente
                    if (!requestSent) {
                        // Enviar solicitud de amistad al usuario
                        sendFriendRequest(user, availableUsers[currentIndex]);
                        availableUsers[currentIndex]->FriendRequestsList->friendRequests[availableUsers[currentIndex]->FriendRequestsList->pendingRequests++] = user;
                    }
                }
                currentIndex++;
                //Confirma que ya se han visitado todos los usuarios ofrecidos
                if (currentIndex >= availableCount) {
                    printf("\nYou have reviewed all available users.\n");
                    finished = 1;
                }
                break;

            case 'n': // En caso de no querer agregar como amigo
                currentIndex++;
                //Confirma que ya se han visitado todos los usuarios ofrecidos
                if (currentIndex >= availableCount) {
                    printf("\nYou have reviewed all available users.\n");
                    finished = 1;
                }
                break;

            case 3: // Salir
                finished = 1;
                break;

            default:
                printf("Invalid option.\n");
                break;
        }
    }
}
