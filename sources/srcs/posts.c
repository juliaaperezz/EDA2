
#include "../headers/posts.h"
#include "../headers/usuarios.h"
#include "../headers/main+menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createPost(User *user);
void listUserPosts(User *user);
void displayTopWords(UserList *list);


//Función para crear publicaciones
void createPost(User *user) {
    if (user->postCount >= MAX_POST_LENGTH) {
        printf("Maximum number of posts reached.\n");
        return;
    }

    char post[MAX_POST_LENGTH];
    printf("Enter your post (up to %d characters): ", MAX_POST_LENGTH);
    //Lectura de lo introducido por el usuario y introducido en la variable post
    fgets(post, MAX_POST_LENGTH, stdin);
    post[strcspn(post, "\n")] = '\0';  // Elimina el carácter de nueva línea del post

    strncpy(user->posts[user->postCount++], post, MAX_POST_LENGTH);  // Agrega el post al usuario y actualiza el contador
    printf("Post created successfully.\n");

}

//Función para listar las publicaciones del usuario
void listUserPosts(User *user) {
    if (user->postCount == 0) {
        printf("No posts found for this user.\n");
        return;
    }

    printf("=== POSTS ===\n");
    for (int i = 0; i < user->postCount; i++) {
        printf("%s\n", user->posts[i]);  // Imprime los posts del usuario
    }
    printf("============\n");
}

//Función para listar las publicaciones de todos los usuarios registrados en la red social
void listAllUsersPosts(UserList *list) {
    if (list->count == 0) {
        printf("No users found.\n");
        return;
    }

    printf("=== ALL USERS' POSTS ===\n");
    for (int i = 0; i < list->count; i++) {
        printf("User %s:\n", list->users[i].username);
        listUserPosts(&list->users[i]);
    }
    printf("========================\n");
}