//
// Created by julia on 09/05/2023.
//

#include "../headers/user_linked.h"
#include "../headers/funciones_menu.h"
#include "../headers/usuario.h"
#include <stdio.h>
#include <stdlib.h>

struct Node{
    Usuario data;  //queremos listar los usuarios
    struct node *prev;
    struct node *next;
};

//initialize nodes
//struct node *head;


//insert a newNode at the end of the list
void insertarUsuario(struct Node **head, Usuario* usuario){
    //allocate memory for node
    struct Node *newNode = NULL;
    newNode = malloc(sizeof(struct Node));

    //assign data to newNode
    Usuario data;
    data = llenarDatosUsuario(usuario);  //preguntar como enlazar los distintos documentos para reutilizar funciones existentes
    //funcion funciones_menu.c
    newNode->data = data;

    //assign NULL to next of newNode
    newNode->next = NULL;

    //store the head node temporarily (for later use)
    struct Node *temp = *head;

    //if the linkedlist is empty, make the newNode as head node
    if(*head == NULL){
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    //if the linked list is not empty transverse to the end of the linkedlist
    while(temp->next != NULL)
        temp = temp->next;

    //point the next of the last node (temp) to newNode
    temp->next = newNode;

    //assign prev of newNode to temp
    newNode->prev = temp;
}

void listarUsers{
    

}