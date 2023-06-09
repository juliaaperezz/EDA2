
#include "../headers/main+menu.h"
#include "../headers/posts.h"
#include "../headers/usuarios.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void displayMenu();
void insertUser(UserList *list);
void readUsersFromFile(const char *filename, UserList *list);
void listAllUsers(UserList *list);
void operateAsUser(UserList *list);
void connectWithStrangers(UserList *list, User *user);
void handleFriendRequests(UserList *list, User *user);
void createPost(User *user);
void listUserPosts(User *user);
void listAllUsersPosts(UserList *list);
void displayTopWords(UserList *list);
User* searchUser(UserList *list, const char *username);
void addFriend(UserList *list, User user);
void addUnknownFriend(User *user, UserList *userList);

//Función principal
int main() {
    //Inicializamos la lista de usuarios
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
                readUsersFromFile(USUARIOS_CSV, &userList);
                break;
            case 3:
                listAllUsers(&userList);
                break;
            case 4:
                operateAsUser(&userList);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

//Función para mostrar en la terminal las múltiples opciones a escoger como funcionalidad
void displayMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Insert a new user\n");
    printf("2. Load users via CSV\n");
    printf("3. List all existing users\n");
    printf("4. Operate as a specific user\n");
    printf("5. Exit\n");
}

// Función para permitir al usuario operar como usuario especifico
void operateAsUser(UserList *list) {
    //Inicialización de variables
    char username[MAX_NAME_LENGTH];
    printf("Enter username: ");
    fgets(username, MAX_NAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0';

    User *user = searchUser(list, username);
    if (user == NULL) {
        printf("User not found.\n");
        return;
    }

    int choice;
    do {
        printf("\n=== USER MENU ===\n");
        printf("1. Send friend requests\n");
        printf("2. Connect with a stranger\n");
        printf("3. Manage pending friend requests\n");
        printf("4. Create a post\n");
        printf("5. List user posts\n");
        printf("6. Top 10 words most used among all users\n");
        printf("7. Go back to the main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addFriend(list, *user);
                break;
            case 2:
                connectWithStrangers(list, user);
                break;
            case 3:
                handleFriendRequests(list, user);
                break;
            case 4:
                createPost(user);
                break;
            case 5:
                listUserPosts(user);
                break;
            case 6:
                displayTopWords(list);
                break;
            case 7:
                printf("Going back to the main menu...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);
}