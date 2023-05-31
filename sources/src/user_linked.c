#include "../headers/funciones_menu.h"
#include "../headers/usuario.h"
#include "../headers/user_linked.h"
#include <stdio.h>
#include <stdlib.h>


//initialize nodes
//struct node *head;


//insert a newNode at the end of the list
void addUsuario(struct Node **head, Usuario* user){
    //allocate memory for node
    struct Node *newNode = NULL;
    newNode = (struct Node*) malloc(sizeof(struct Node));

    //assign data to newNode
    newNode->data = *user;

    //assign NULL to next of newNode
    newNode->next = NULL;

    //store the head node temporarily (for later use)
    struct Node temp = **head;

    //if the linkedlist is empty, make the newNode as head node
    if(head == NULL){
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    //if the linked list is not empty transverse to the end of the linkedlist
    while(temp.next != NULL)

        temp = *temp.next;

    //point the next of the last node (temp) to newNode
    temp.next = newNode;

    //assign prev of newNode to temp
    newNode->prev = &temp;

    //debug
    printf("DEBUG: add user D2\n");
    //print data from head
    printf("user added is %s\n", (*head)->data.nombreUsuario);

    printf("user age is %d\n", (*head)->data.edad);




}


void listarUsuarios(struct Node *head){
    int counter = 1;
    struct Node* current = head;
    while(current != NULL){
        printf("%d. %s \n", counter, current->data.nombreUsuario);
        current = current->next;
        counter++;
    }
}
