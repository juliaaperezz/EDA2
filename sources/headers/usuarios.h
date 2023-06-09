//
// Created by julia on 06/06/2023.
//

#ifndef UNTITLED6_USUARIOS_H
#define UNTITLED6_USUARIOS_H

#endif //UNTITLED6_USUARIOS_H

#define MAX_USERS 50
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_LOCATION_LENGTH 50
#define MAX_PREFERENCES 5
#define MAX_POST_LENGTH 120
#define MAX_TOP_WORDS 10

// Definición de la estructura User que representa a un usuario
typedef struct {
    char username[MAX_NAME_LENGTH];
    int age;
    char email[MAX_EMAIL_LENGTH];
    char location[MAX_LOCATION_LENGTH];
    char preferences[MAX_PREFERENCES][MAX_NAME_LENGTH];
    char posts[MAX_POST_LENGTH][MAX_POST_LENGTH];
    int postCount;
    struct FriendsList *Friends;  // Puntero a la lista de amigos
    struct FriendRequestsList *FriendRequestsList;  // Puntero a la lista de solicitudes de amistad
} User;

// Definición de la estructura UserList que contiene una lista de usuarios
typedef struct UserList {
    User users[MAX_USERS];  // Arreglo de usuarios
    int count;  // Contador de usuarios
} UserList;

// Definición de la estructura FriendsList que contiene la lista de amigos de un usuario
typedef struct FriendsList {
    User *friends[MAX_USERS];  // Arreglo de punteros a usuarios que representan a los amigos
    int friendsCount;  // Contador de amigos
} FriendsList;

// Definición de la estructura FriendRequestsList que contiene la lista de solicitudes de amistad de un usuario
typedef struct FriendRequestsList {
    User *friendRequests[MAX_USERS];  // Arreglo de punteros a usuarios que representan las solicitudes de amistad
    int pendingRequests;  // Contador de solicitudes pendientes
    struct Stack* stack;  // Puntero a una pila
} FriendRequestsList;

// Definición de la estructura Node que representa un nodo en una lista enlazada
typedef struct Node {
    User *data;  // Puntero a un usuario
    struct Node *next;  // Puntero al siguiente nodo
} Node;

// Definición de la estructura Stack que representa una pila
typedef struct {
    Node *top;  // Puntero al nodo superior de la pila
} Stack;

// Definición de la estructura QueueNode que representa un nodo en una cola
typedef struct QueueNode {
    User *data;  // Puntero a un usuario
    struct QueueNode *next;  // Puntero al siguiente nodo
} QueueNode;

// Definición de la estructura Queue que representa una cola
typedef struct {
    QueueNode *front;  // Puntero al nodo frontal de la cola
    QueueNode *rear;  // Puntero al nodo trasero de la cola
} Queue;
