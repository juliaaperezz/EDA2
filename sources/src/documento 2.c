/*
//
// Created by Carla Núñez Viñas on 3/6/23.
//

#include "../headers/documento 2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 20
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_LOCATION_LENGTH 50
#define MAX_PREFERENCES 5
#define MAX_POST_LENGTH 120
#define MAX_TOP_WORDS 10

// Estructura de usuario
typedef struct {
    char username[MAX_NAME_LENGTH];
    int age;
    char email[MAX_EMAIL_LENGTH];
    char location[MAX_LOCATION_LENGTH];
    char preferences[MAX_PREFERENCES][MAX_NAME_LENGTH];
    char posts[MAX_POST_LENGTH][MAX_POST_LENGTH];
    int postCount;
} User;

// Lista dinámica de usuarios
typedef struct {
    User users[MAX_USERS];
    int count;
} UserList;

// Prototipos de funciones
void displayMenu();
void insertUser(UserList *list);
void listAllUsers(UserList list);
void operateAsUser(UserList list);
User* searchUser(UserList list, const char *username);
void addFriend(UserList list, User *user);
void connectWithStrangers(UserList list, User *user);
void handleFriendRequests(User *user);
void createPost(User *user);
void listUserPosts(User *user);
void displayTopWords(UserList list);

// Función principal
int main() {
    UserList userList;
    userList.count = 0;

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Limpiar el búfer de entrada

        switch (choice) {
            case 1:
                insertUser(&userList);
                break;
            case 2:
                listAllUsers(userList);
                break;
            case 3:
                operateAsUser(userList);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Función para mostrar el menú
void displayMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Insert a new user\n");
    printf("2. List all existing users\n");
    printf("3. Operate as a specific user\n");
    printf("4. Exit\n");
}

// Función para insertar un nuevo usuario
void insertUser(UserList *list) {
    if (list->count >= MAX_USERS) {
        printf("User list is full. Cannot insert more users.\n");
        return;
    }

    User newUser;
    printf("Enter username: ");
    fgets(newUser.username, MAX_NAME_LENGTH, stdin);
    newUser.username[strcspn(newUser.username, "\n")] = '\0'; // Eliminar el salto de línea
    printf("Enter age: ");
    scanf("%d", &newUser.age);
    getchar(); // Limpiar el búfer de entrada
    printf("Enter email: ");
    fgets(newUser.email, MAX_EMAIL_LENGTH, stdin);
    newUser.email[strcspn(newUser.email, "\n")] = '\0'; // Eliminar el salto de línea
    printf("Enter location: ");
    fgets(newUser.location, MAX_LOCATION_LENGTH, stdin);
    newUser.location[strcspn(newUser.location, "\n")] = '\0'; // Eliminar el salto de línea
    printf("Enter preferences (up to %d, one per line):\n", MAX_PREFERENCES);
    for (int i = 0; i < MAX_PREFERENCES; i++) {
        fgets(newUser.preferences[i], MAX_NAME_LENGTH, stdin);
        newUser.preferences[i][strcspn(newUser.preferences[i], "\n")] = '\0'; // Eliminar el salto de línea
    }

    newUser.postCount = 0;

    list->users[list->count++] = newUser;
    printf("User inserted successfully.\n");
}

// Función para listar todos los usuarios
void listAllUsers(UserList list) {
    if (list.count == 0) {
        printf("No users found.\n");
        return;
    }

    printf("=== USER LIST ===\n");
    for (int i = 0; i < list.count; i++) {
        printf("Username: %s\n", list.users[i].username);
        printf("Age: %d\n", list.users[i].age);
        printf("Email: %s\n", list.users[i].email);
        printf("Location: %s\n", list.users[i].location);
        printf("Preferences:\n");
        for (int j = 0; j < MAX_PREFERENCES; j++) {
            printf("- %s\n", list.users[i].preferences[j]);
        }
        printf("================\n");
    }
}

// Función para operar como un usuario específico
void operateAsUser(UserList list) {
    char username[MAX_NAME_LENGTH];
    printf("Enter username: ");
    fgets(username, MAX_NAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0'; // Eliminar el salto de línea

    User *user = searchUser(list, username);
    if (user == NULL) {
        printf("User not found.\n");
        return;
    }

    int choice;
    do {
        printf("\n=== USER MENU ===\n");
        printf("1. Send friend requests\n");
        printf("2. Manage pending friend requests\n");
        printf("3. Create a post\n");
        printf("4. List user posts\n");
        printf("5. Go back to the main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Limpiar el búfer de entrada

        switch (choice) {
            case 1:
                addFriend(list, user);
                break;
            case 2:
                handleFriendRequests(user);
                break;
            case 3:
                createPost(user);
                break;
            case 4:
                listUserPosts(user);
                break;
            case 5:
                printf("Going back to the main menu...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}

// Función para buscar un usuario por su nombre de usuario
User* searchUser(UserList list, const char *username) {
    for (int i = 0; i < list.count; i++) {
        if (strcmp(list.users[i].username, username) == 0) {
            return &list.users[i];
        }
    }
    return NULL;
}

// Función para agregar un amigo
void addFriend(UserList list, User *user) {
    char username[MAX_NAME_LENGTH];
    printf("Enter the username of the person you want to add as a friend: ");
    fgets(username, MAX_NAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0'; // Eliminar el salto de línea

    User *friend = searchUser(list, username);
    if (friend == NULL) {
        printf("User not found.\n");
        return;
    }

    // Envía una solicitud de amistad aquí

    printf("Friend request sent to %s.\n", friend->username);
}

// Función para conectarse con desconocidos
void connectWithStrangers(UserList list, User *user) {
    // Seleccionar 3 usuarios aleatorios que no estén en la lista de amigos del usuario
    // y agregarlos a una pila (Stack)
    // Luego, recorrer la pila y permitir al usuario decidir si desea agregar a cada persona o no
    // Puedes implementar esto como una función adicional
}

// Función para manejar las solicitudes de amistad
void handleFriendRequests(User *user) {
    // Mostrar las solicitudes de amistad pendientes y permitir al usuario aprobar o denegar cada solicitud
    // Puedes implementar esto como una función adicional
}

// Función para crear una publicación
void createPost(User *user) {
    if (user->postCount >= MAX_POST_LENGTH) {
        printf("Maximum number of posts reached.\n");
        return;
    }

    char post[MAX_POST_LENGTH];
    printf("Enter your post (up to %d characters): ", MAX_POST_LENGTH);
    fgets(post, MAX_POST_LENGTH, stdin);
    post[strcspn(post, "\n")] = '\0'; // Eliminar el salto de línea

    strncpy(user->posts[user->postCount++], post, MAX_POST_LENGTH);
    printf("Post created successfully.\n");
}

// Función para listar las publicaciones de un usuario
void listUserPosts(User *user) {
    if (user->postCount == 0) {
        printf("No posts found for this user.\n");
        return;
    }

    printf("=== POSTS ===\n");
    for (int i = 0; i < user->postCount; i++) {
        printf("%s\n", user->posts[i]);
    }
    printf("============\n");
}

// Función para mostrar las 10 palabras más usadas en las publicaciones de todos los usuarios
void displayTopWords(UserList list) {
    // Implementa un sistema de conteo de palabras y muestra las 10 más usadas
    // Puedes implementar esto como una función adicional
}
*/
