//
// Created by julia on 09/05/2023.
//

#ifndef EDA2_PROYECTO_USER_LINKED_H
#define EDA2_PROYECTO_USER_LINKED_H
#include "usuario.h"

struct Node{
    Usuario data;  //queremos listar los usuarios
    struct Node *prev;
    struct Node *next;
};
#endif //EDA2_PROYECTO_USER_LINKED_H

struct Node* buscarUsuario(struct Node *head, char *nombreUsuario);
void listarUsuarios(struct Node* head);
void addUsuario(struct Node **head, Usuario* user);