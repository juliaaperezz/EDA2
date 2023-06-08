

#include "../headers/stack_strangers.h"
#include "../headers/usuarios.h"
#include "../headers/main+menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void sendFriendRequest(User *sender, User *receiver);

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, User* item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

User* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow.\n");
        return NULL;
    }
    Node* temp = stack->top;
    User* item = temp->data;
    stack->top = temp->next;
    free(temp);
    return item;
}

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


void connectWithStrangers(UserList* list, User* user) {
    int numStrangers = 0;
    User* strangers[MAX_USERS];

    // Seleccionar 3 usuarios aleatorios que no estén en la lista de amigos del usuario
    // y agregarlos a una pila (Stack)
    for (int i = 0; i < list->count; i++) {
        User* currUser = &list->users[i];
        if (currUser != user) {
            int isFriend = 0;
            for (int j = 0; j < user->Friends->friendsCount; j++) {
                if (strcmp(currUser->username, user->Friends->friends[j]->username) == 0) {
                    isFriend = 1;
                    break;
                }
            }
            if (!isFriend) {
                strangers[numStrangers++] = currUser;
            }
        }
    }

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

    for (int i = 0; i < 3; i++) {
        push(stack, strangers[i]);
    }

    // Assign the stack to user's FriendRequestsList struct
    user->FriendRequestsList->stack = stack;

    // Recorrer la pila y permitir al usuario decidir si desea enviar una solicitud de amistad a cada persona o no
    while (!isEmpty(user->FriendRequestsList->stack)) {
        User* stranger = pop(user->FriendRequestsList->stack);
        printf("Do you want to send a friend request to %s? (y/n): ", stranger->username);
        char choice;
        scanf(" %c", &choice);
        getchar();

        if (choice == 'y' || choice == 'Y') {
            // Verificar si el amigo ya tiene una solicitud de amistad pendiente
            int requestSent = 0;
            for (int i = 0; i < stranger->FriendRequestsList->pendingRequests; i++) {
                if (strcmp(stranger->FriendRequestsList->friendRequests[i]->username, user->username) == 0) {
                    printf("Friend request already sent to user %s.\n", stranger->username);
                    requestSent = 1;
                    break;
                }
            }

            if (!requestSent) {
                // Enviar solicitud de amistad al usuario
                sendFriendRequest(user, stranger);
                user->FriendRequestsList->friendRequests[user->FriendRequestsList->pendingRequests++] = stranger;
            }
        }
    }

    free(stack);
}
