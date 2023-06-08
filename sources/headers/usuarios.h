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


typedef struct User {
    char username[MAX_NAME_LENGTH];
    int age;
    char email[MAX_EMAIL_LENGTH];
    char location[MAX_LOCATION_LENGTH];
    char preferences[MAX_PREFERENCES][MAX_NAME_LENGTH];
    char posts[MAX_POST_LENGTH][MAX_POST_LENGTH];
    int postCount;
    struct FriendsList *Friends;
    struct FriendRequestsList *FriendRequestsList;
} User;

//lista de todos los usuarios
typedef struct UserList {
    User users[MAX_USERS];
    int count;
} UserList;

//lista de amigos dde cada usuario
typedef struct FriendsList {
    User *friends[MAX_USERS];
    int friendsCount;
} FriendsList;

//lista de solicitudes de cada amigo
typedef struct FriendRequestsList {
    User *friendRequests[MAX_USERS];
    int pendingRequests;
    struct Stack* stack;
} FriendRequestsList;

typedef struct Node {
    User *data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

typedef struct QueueNode {
    User *data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;
