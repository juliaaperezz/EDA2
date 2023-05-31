#include "../headers/funciones_menu.h"
#include "../headers/usuario.h"
#include "../headers/user_linked.h"
#include <stdio.h>
#include <stdlib.h>


//initialize nodes
//struct node *head;


//insert a newNode at the end of the list
void addUsuario(struct Node **head, Usuario* user) {
    // Allocate memory for newNode
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // Assign data to newNode
    newNode->data = *user;

    // Assign NULL to next of newNode
    newNode->next = NULL;

    // If the linked list is empty, make newNode as the head node
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Traverse to the end of the linked list
    struct Node* current = *head;
    while (current->next != NULL)
        current = current->next;

    // Point the next of the last node to newNode
    current->next = newNode;

    // Assign prev of newNode to current
    newNode->prev = current;
}

void listarUsuarios(struct Node* head) {
    int counter = 1;
    struct Node* current = head;
    while (current != NULL) {
        printf("%d. %s\n", counter, current->data.nombreUsuario);
        current = current->next;
        counter++;
    }
}

