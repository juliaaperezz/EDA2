

#include "../headers/main+menu.h"
#include "../headers/usuarios.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"

void listAllUsers(UserList *list);
void operateAsUser(UserList *list);

User* searchUser(UserList *list, const char *username);
void initializeQueue(Queue *queue);
int isQueueEmpty(Queue *queue);
void enqueue(Queue *queue, User *data);
User *dequeue(Queue *queue);
void addFriend(UserList *list, User user);
void connectWithStrangers(UserList *list, User *user);
void handleFriendRequests(UserList *list, User *user);
void createPost(User *user);
void listUserPosts(User *user);
void displayTopWords(UserList *list);
void addUnknownFriend(User *user, UserList *userList);
void readUsersFromFile(const char *filename, UserList *list);
void merge(User* arr, int left, int middle, int right);
void mergeSort(User* arr, int left, int right);


// Función para validar el formato del email
int validateEmail(const char *email) {
    int atIndex = -1;
    int dotIndex = -1;

    // Verifica que el mail tiene al menos un carácter antes de '@' y después de '.'
    int len = strlen(email);
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            atIndex = i;
        } else if (email[i] == '.') {
            dotIndex = i;
        }
    }
    // Chequea que el mail tiene un formato correcto
    if (atIndex == -1 || dotIndex == -1 || atIndex > dotIndex) {
        return 0; // El mail no tiene un formato correcto
    }
    return 1; // El mail es válido
}

// Función para insertar un usuario en la red social
void insertUser(UserList *list) {
    if (list->count >= MAX_USERS) {
        printf("User list is full. Cannot insert more users.\n");
        return;
    }

    //Entrada de datos del usuario
    User newUser;
    printf("Enter username: ");
    fgets(newUser.username, MAX_NAME_LENGTH, stdin);
    newUser.username[strcspn(newUser.username, "\n")] = '\0';

    printf("Enter age: ");
    scanf("%d", &newUser.age);
    getchar();   // Limpia el búfer del carácter de nueva línea después de leer la edad

    int validEmail = 0;
    while (!validEmail) {
        printf("Enter email: ");
        fgets(newUser.email, MAX_EMAIL_LENGTH, stdin);
        newUser.email[strcspn(newUser.email, "\n")] = '\0';

        if (validateEmail(newUser.email)) {
            validEmail = 1;
        } else {
            printf("Invalid email. Please enter a valid email. \n");
        }
    }

    printf("Enter location: ");
    fgets(newUser.location, MAX_LOCATION_LENGTH, stdin);
    newUser.location[strcspn(newUser.location, "\n")] = '\0';

    printf("Enter preferences (up to %d, one per line):\n", MAX_PREFERENCES);
    for (int i = 0; i < MAX_PREFERENCES - 1; i++) {
        fgets(newUser.preferences[i], MAX_NAME_LENGTH, stdin);
        newUser.preferences[i][strcspn(newUser.preferences[i], "\n")] = '\0';
    }
    getchar();

    //Inicializamos y reservamos memoria para las listas dinamicas de cada usuario
    newUser.Friends = malloc(sizeof(FriendsList));
    newUser.Friends->friendsCount = 0;
    newUser.FriendRequestsList = malloc(sizeof(FriendRequestsList));
    newUser.FriendRequestsList->pendingRequests = 0;
    newUser.postCount = 0;

    //Añadimos los usuarios a la lista de usuarios
    list->users[list->count] = newUser;
    list->count++;

    printf("User %s inserted successfully.\n", newUser.username);
}

// Función para listar todos los usuarios registrados en la red social
void listAllUsers(UserList *list) {
    if (list->count == 0) {
        printf("No users found.\n");
        return;
    }

    // Ordenar los usuarios por edad utilizando MergeSort
    mergeSort(list->users, 0, list->count - 1);

    // Listado de usuarios
    printf("\n=== USER LIST ===\n\n");
    for (int i = 0; i < list->count; i++) {
        printf("Username: %s\n", list->users[i].username);
        printf("Age: %d\n", list->users[i].age);
        printf("Email: %s\n", list->users[i].email);
        printf("Location: %s\n", list->users[i].location);
        printf("================\n");
    }
}

// Función para buscar los usuarios en la lista de usuarios
User* searchUser(UserList *list, const char *username) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->users[i].username, username) == 0) {
            return &list->users[i];  // Devuelve un puntero al usuario encontrado
        }
    }
    return NULL;  // No se encontró ningún usuario con el nombre de usuario especificado
}

// Haremos uso de las colas para la sección de solicitudes
// Inicializar una cola vacía
void initializeQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Verificar si la cola está vacía
int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}

// Insertar un elemento en la cola
void enqueue(Queue *queue, User *data) {
    QueueNode *newNode = malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Eliminar y devolver el elemento frontal de la cola
User *dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }

    QueueNode *temp = queue->front;
    User *data = temp->data;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
    return data;
}

//Añade un usuario a la lista de friend requests al usuario que quiera como amigo
void addFriend(UserList *list, User user) {
    char friendUsername[MAX_NAME_LENGTH];
    printf("Enter the username of the friend: ");
    fgets(friendUsername, MAX_NAME_LENGTH, stdin);
    strtok(friendUsername, "\n");

    // Busca el amigo en la lista de usuarios
    User *friend = searchUser(list, friendUsername); //retorna la estructura User de friend

    //Verifica que el amigo está registrado en la aplicación
    if (friend == NULL) {
        printf("Friend not found.\n");
        return;
    }

    //Comprueba que el usuario no se envia una solicitud a si mismo
    if (strcmp(friend->username, user.username) == 0){
        printf("You can't send a friend request to yourself.\n");
        return;
    }

    // Verifica si el amigo ya tiene una solicitud de amistad pendiente
    for (int i = 0; i < friend->FriendRequestsList->pendingRequests; i++) {
        if (strcmp(friend->FriendRequestsList->friendRequests[i]->username, user.username) == 0) {
            printf("Friend request already sent to user %s.\n", friend->username);
            return;
        }
    }

    // Verifica si ya son amigos
    for (int i = 0; i < friend->Friends->friendsCount; i++) {
        if (strcmp(friend->Friends->friends[i]->username, user.username) == 0) {
            printf("You and %s are already friends.\n", friend->username);
            return;
        }
    }

    // Agrega solicitud de amistad al amigo
    friend->FriendRequestsList->friendRequests[friend->FriendRequestsList->pendingRequests] = malloc(sizeof(User));
    memcpy(friend->FriendRequestsList->friendRequests[friend->FriendRequestsList->pendingRequests], &user, sizeof(User));
    friend->FriendRequestsList->pendingRequests++;
    printf("Friend request sent to user %s.\n", friend->username);
}

//Implmentación para manejar las solicitudes pendientes con colas
void handleFriendRequests(UserList *list, User *user) {
    if (user->FriendRequestsList->pendingRequests == 0) {
        printf("No pending friend requests.\n");
        return;
    }

    // Inicialización de una cola
    Queue requestQueue;
    initializeQueue(&requestQueue);

    // Insertar las solicitudes de amistad en la cola
    for (int i = 0; i < user->FriendRequestsList->pendingRequests; i++) {
        enqueue(&requestQueue, user->FriendRequestsList->friendRequests[i]);
    }

    //En caso que la cola no esté vacía, muestra las solicitudes de amistad pendientes
    while (!isQueueEmpty(&requestQueue)) {
        // Sacamos de la cola el primer usuario que envio una solicitud de amistad
        User *requestingUser = dequeue(&requestQueue);
        // Buscamos el usuario en la lista de usuarios registrados en la red social
        User *friend = searchUser(list, requestingUser->username);
        int counter = 0;
        printf("=== Friend Requests ===\n");
        printf("You have %d pending requests\n", requestQueue.rear - requestQueue.front + 1);

        printf("Username: %s\n", requestingUser->username);
        char option;
        printf("Do you want to know more about the requesting user? (y/n) ");
        scanf("%c", &option);
        getchar();
        //En caso de querer conocer los detalles del usuario que envía la solicitud se muestran por pantalla sus datos
        if (option == 'y' || option == 'Y'){
            printf("Username: %s\n", requestingUser->username);
            printf("Age: %d\n", requestingUser->age);
            printf("Email: %s\n", requestingUser->email);
            printf("Location: %s\n", requestingUser->location);
            printf("Preferences: ");
            for (int j = 0; j < MAX_PREFERENCES; j++) {
                printf("%s ", requestingUser->preferences[j]);
            }
            printf("\n");
        }

        // Pedimos al usuario que introduzca si quiere o no aceptar la solicitud
        char choice;
        printf("Do you want to accept this friend request? (y/n): ");
        scanf("%c", &choice);
        getchar();

        //En caso que se quiera añadir al usuario como amigo
        if (choice == 'y' || choice == 'Y') {
            // Agregar amigo
            if (user->Friends->friendsCount >= MAX_USERS) {
                printf("User has reached the maximum number of friends.\n");
                return;
            }
            //Añadimos el solicitante a la lista de amigos del usuario operador
            user->Friends->friends[user->Friends->friendsCount] = requestingUser;
            user->Friends->friendsCount++;
            // Agregar amigo a la lista del solicitante
            friend->Friends->friends[friend->Friends->friendsCount] = user;
            friend->Friends->friendsCount++;

            // Eliminar solicitud de amistad para revisar la siguiente en caso que haya
            for (int j = counter; j < user->FriendRequestsList->pendingRequests - 1; j++) {
                user->FriendRequestsList->friendRequests[j] = user->FriendRequestsList->friendRequests[j + 1];
            }
            //Se actualiza el número de solicitudes pendientes
            user->FriendRequestsList->pendingRequests--;
            printf("Friend request accepted.\nUser %s added to friends list.\n", requestingUser->username);
        } else if (choice == 'n' || choice == 'N') {
            // Rechazar solicitud de amistad
            for (int j = counter; j < user->FriendRequestsList->pendingRequests - 1; j++) {
                user->FriendRequestsList->friendRequests[j] = user->FriendRequestsList->friendRequests[j + 1];
            }
            //Se actualiza el número de solicitudes pendientes
            user->FriendRequestsList->pendingRequests--;
            printf("Friend request rejected.\n");
        } else {
            printf("Invalid option. Please try again.\n");
            enqueue(&requestQueue, requestingUser);
        }
        counter++;
        printf("=======================\n");
    }

    // Verificar si no se mostraron solicitudes pendientes para el usuario actual
    if (user->FriendRequestsList->pendingRequests == 0) {
        printf("No pending friend requests.\n");
    }
}


//USUARIOS VIA CSV

// Función para leer los datos de usuarios desde un archivo CSV
void readUsersFromFile(const char *filename, UserList *list) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo %s.\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        User user;
        char *token;

        // Obtener el nombre de usuario
        token = strtok(line, ",");
        strncpy(user.username, token, MAX_NAME_LENGTH);

        // Obtener la edad
        token = strtok(NULL, ",");
        user.age = atoi(token);

        // Obtener el email
        token = strtok(NULL, ",");
        strncpy(user.email, token, MAX_EMAIL_LENGTH);

        // Obtener la ubicación
        token = strtok(NULL, ",");
        strncpy(user.location, token, MAX_LOCATION_LENGTH);

        // Obtener las preferencias
        token = strtok(NULL, ",");
        int preferenceIndex = 0;
        while (token != NULL && preferenceIndex < MAX_PREFERENCES) {
            strncpy(user.preferences[preferenceIndex], token, MAX_NAME_LENGTH);
            preferenceIndex++;
            token = strtok(NULL, ",");
        }

        //Inicializamos y reservamos memoria para las listas dinamicas de cada usuario
        user.Friends = malloc(sizeof(FriendsList));
        user.Friends->friendsCount = 0;
        user.FriendRequestsList = malloc(sizeof(FriendRequestsList));
        user.FriendRequestsList->pendingRequests = 0;

        //Añadimos los usuarios a la lista de usuarios
        list->users[list->count] = user;
        list->count++;
    }
    // Cerramos el archivo antes de finalizar la función
    fclose(file);
    printf("Users uploaded correctly.\n");
}