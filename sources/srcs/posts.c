
#include "../headers/posts.h"
#include "../headers/main+menu.h"

#include <stdio.h>
#include <string.h>

void createPost(User *user);
void listUserPosts(User *user);



void createPost(User *user) {
    if (user->postCount >= MAX_POST_LENGTH) {
        printf("Maximum number of posts reached.\n");
        return;
    }

    char post[MAX_POST_LENGTH];
    printf("Enter your post (up to %d characters): ", MAX_POST_LENGTH);
    fgets(post, MAX_POST_LENGTH, stdin);
    post[strcspn(post, "\n")] = '\0';  // Elimina el carácter de nueva línea del post

    strncpy(user->posts[user->postCount++], post, MAX_POST_LENGTH);  // Agrega el post al usuario y actualiza el contador
    printf("Post created successfully.\n");

}

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

