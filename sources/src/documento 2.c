//
// Created by Carla Núñez Viñas on 4/6/23.
//

//#include "../headers/document r.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int friendsCount;   //también se puede utilizar el sizeof(friends)
} FriendsList;

//lista de solicitudes de cada amigo
typedef struct FriendRequestsList {
    User *friendsRequests[MAX_USERS];
    int pendingRequests;
} FriendRequestsList;


void displayMenu();
void insertUser(UserList *list);
void listAllUsers(UserList *list);
void operateAsUser(UserList *list);

User* searchUser(UserList *list, const char *username);
void addFriend(UserList *list, User user);
void connectWithStrangers(UserList *list, User *user);
void handleFriendRequests(User *user);
void createPost(User *user);
void listUserPosts(User *user);
void displayTopWords(UserList *list);
//void loadUsersFromFile(UserList *userList);

int main() {
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
                //loadUsersFromFile(&userList);
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
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Insert a new user\n");
    printf("2. Load user data via CSV\n");
    printf("3. List all existing users\n");
    printf("4. Operate as a specific user\n");
    printf("5. Exit\n");
}

void insertUser(UserList *list) {
    if (list->count >= MAX_USERS) {
        printf("User list is full. Cannot insert more users.\n");
        return;
    }

    User newUser;
    printf("Enter username: ");
    fgets(newUser.username, MAX_NAME_LENGTH, stdin);
    newUser.username[strcspn(newUser.username, "\n")] = '\0';
    printf("Enter age: ");
    scanf("%d", &newUser.age);
    getchar();
    printf("Enter email: ");
    fgets(newUser.email, MAX_EMAIL_LENGTH, stdin);
    newUser.email[strcspn(newUser.email, "\n")] = '\0';
    printf("Enter location: ");
    fgets(newUser.location, MAX_LOCATION_LENGTH, stdin);
    newUser.location[strcspn(newUser.location, "\n")] = '\0';
    printf("Enter preferences (up to %d, one per line):\n", MAX_PREFERENCES);
    for (int i = 0; i < MAX_PREFERENCES; i++) {
        fgets(newUser.preferences[i], MAX_NAME_LENGTH, stdin);
        newUser.preferences[i][strcspn(newUser.preferences[i], "\n")] = '\0';
    }

    newUser.postCount = 0;

    //inicializamos lista friends
    FriendsList friendsList;
    friendsList.friendsCount = 0;

    //inicializamos lista requests
    FriendRequestsList friendRequestsList;
    friendRequestsList.pendingRequests = 0;


    list->users[list->count++] = newUser;
    //falta actualizar count
    printf("User inserted successfully.\n");
}

void listAllUsers(UserList *list) {
    if (list->count == 0) {
        printf("No users found.\n");
        return;
    }

    printf("=== USER LIST ===\n");
    for (int i = 0; i < list->count; i++) {
        printf("Username: %s\n", list->users[i].username);
        printf("Age: %d\n", list->users[i].age);
        printf("Email: %s\n", list->users[i].email);
        printf("Location: %s\n", list->users[i].location);
        printf("Preferences:\n");
        for (int j = 0; j < MAX_PREFERENCES; j++) {
            printf("- %s\n", list->users[i].preferences[j]);
        }
        printf("================\n");
    }
}

void operateAsUser(UserList *list) {
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
                handleFriendRequests(user);
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
                //displayMenu();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);
}

User* searchUser(UserList *list, const char *username) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->users[i].username, username) == 0) {
            return &list->users[i];
        }
    }
    return NULL;
}

void addFriend(UserList *list, User user) {
    char username[MAX_NAME_LENGTH];

    if (user.Friends->friendsCount >= MAX_USERS) {
        printf("Friend list is full. Cannot add more friends.\n");
        return;
    }

    printf("Enter the username of the person you want to add as a friend: ");
    fgets(username, MAX_NAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0';

    User* friend = searchUser(list, username);

    if (friend == NULL) {
        printf("User not found.\n");
        return;
    }
/*
    // Check if the user is already friends with the given friend
    for (int i = 0; i < sizeof(user.Friends->friends); i++) { //////lo he cambiado
        if (strcmp(friend->username, user.Friends->friends[i]->username) == 0) {
            printf("You are already friends with %s.\n", friend->username);
            return;
        }
    }

    printf("sii\n");
    // Check if the friend has already sent a friend request
    for (int i = 0; i < sizeof(user.FriendRequestsList->friendsRequests); i++) {
        printf("siiii\n");
        if (strcmp(friend->username, user.FriendRequestsList->friendsRequests[i]->username) == 0) {
            printf("You have already received a friend request from %s.\n", friend->username);
            return;
        }
        printf("siaa\n");
    }*/
    printf("sip\n");
    /* // Add friend by sending a friend request
     if (sizeof(friend->FriendRequestsList->friendsRequests) == MAX_USERS) {
         printf("This user has reached the maximum of requests permitted.\n");
         return;
     }*/
    printf("siaa\n");
    friend->FriendRequestsList->friendsRequests[friend->FriendRequestsList->pendingRequests++] = &user;
    printf("si\n");
    friend->FriendRequestsList->pendingRequests++;  //actualizar pending requests

    printf("Friend request sent to %s.\n", friend->username);
}

void connectWithStrangers(UserList *list, User *user) {
    int numStrangers = 0;
    User *strangers[MAX_USERS];

    // Seleccionar 3 usuarios aleatorios que no estén en la lista de amigos del usuario
    // y agregarlos a una pila (Stack)
    for (int i = 0; i < list->count; i++) {
        User *currUser = &list->users[i];
        if (currUser != user) {
            int isFriend = 0;
            for (int j = 0; j < user->Friends->friendsCount; j++) {
                if (strcmp(currUser->username, user->Friends->friends[j]->username) == 0) {
                    isFriend = 1;
                    break;  //sospechoso
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
    for (int i = 0; i < numStrangers - 1; i++) {
        int j = i + rand() / (RAND_MAX / (numStrangers - i) + 1);
        User *temp = strangers[j];
        strangers[j] = strangers[i];
        strangers[i] = temp;
    }

    // Create a stack for the strangers
    User *stack[MAX_USERS];
    int top = -1;

    for (int i = 0; i < 3; i++) {
        stack[++top] = strangers[i];
    }

    // Recorrer la pila y permitir al usuario decidir si desea agregar a cada persona o no
    while (top >= 0) {
        User *stranger = stack[top--];
        printf("Do you want to add %s as a friend? (y/n): ", stranger->username);
        char choice;
        scanf("%c", &choice);
        getchar();

        if (choice == 'y' || choice == 'Y') {
            addFriend(list, *user); //(list, stranger)
        }
    }
}

void handleFriendRequests(User *user) {

    if (user->FriendRequestsList->pendingRequests == 0) {
        printf("No pending friend requests.\n");
        return;
    }

    printf("=== PENDING FRIEND REQUESTS ===\n");
    for (int i = 0; i < user->FriendRequestsList->pendingRequests; i++) {
        printf("Username: %s\n", user->FriendRequestsList->friendsRequests[i]->username);
        printf("Age: %d\n", user->FriendRequestsList->friendsRequests[i]->age);
        printf("Email: %s\n", user->FriendRequestsList->friendsRequests[i]->email);
        printf("Location: %s\n", user->FriendRequestsList->friendsRequests[i]->location);
        printf("==============================\n");

        printf("Do you want to accept the friend request from %s? (y/n): ", user->FriendRequestsList->friendsRequests[i]->username);
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            // Add the friend to the user's friend list
            user->Friends->friends[user->Friends->friendsCount++] = user->FriendRequestsList->friendsRequests[i];
            //ns si hace falta actualizar el user->Friends->friendsCount++
            printf("Friend request accepted. %s added to your friend list.\n", user->Friends->friends[user->Friends->friendsCount]->username);  //asi comprobamos que esta en la lista

            // Add the user to the friend's friend list
            user->Friends->friends[user->Friends->friendsCount]->Friends->friends[user->Friends->friends[user->Friends->friendsCount]->Friends->friendsCount++] = user;
            //user->friendList[user->friendCount]->friendCount++;  //actualizar contadorfriendCount friend
            printf("%s added to %s's friend list.\n", user->username, user->FriendRequestsList->friendsRequests[i]->username);

            // Remove the friend request
            for (int j = i; j < user->FriendRequestsList->pendingRequests - 1; j++) {
                user->FriendRequestsList->friendsRequests[j] = user->FriendRequestsList->friendsRequests[j + 1];
            }
            user->FriendRequestsList->pendingRequests--;
            i--;
        }
    }
}

void createPost(User *user) {
    if (user->postCount >= MAX_POST_LENGTH) {
        printf("Maximum number of posts reached.\n");
        return;
    }

    char post[MAX_POST_LENGTH];
    printf("Enter your post (up to %d characters): ", MAX_POST_LENGTH);
    fgets(post, MAX_POST_LENGTH, stdin);
    post[strcspn(post, "\n")] = '\0';

    strncpy(user->posts[user->postCount++], post, MAX_POST_LENGTH);
    printf("Post created successfully.\n");
    //user->postCount++;
}

void listUserPosts(User *user) {
    if (user->postCount == 0) {
        printf("No posts found for this user.\n");
        return;
    }

    printf("=== POSTS ===\n");
    for (int i = 0; i < user->postCount; i++) {
        printf("%s\n", user->posts[i]);
    }
    printf("============\n");
}

void displayTopWords(UserList *list) {
    int wordCount[MAX_TOP_WORDS] = {0};
    char topWords[MAX_TOP_WORDS][MAX_NAME_LENGTH];

    for (int i = 0; i < list->count; i++) {
        User *user = &list->users[i];
        for (int j = 0; j < user->postCount; j++) {
            char *word = strtok(user->posts[j], " ");
            while (word != NULL) {
                int index = -1;
                for (int k = 0; k < MAX_TOP_WORDS; k++) {
                    if (strcmp(word, topWords[k]) == 0) {
                        index = k;
                        break;
                    }
                }
                if (index == -1) {
                    // Word not found in topWords array, add it
                    for (int k = 0; k < MAX_TOP_WORDS; k++) {
                        if (wordCount[k] == 0) {
                            strncpy(topWords[k], word, MAX_NAME_LENGTH);
                            index = k;
                            break;
                        }
                    }
                }
                if (index != -1) {
                    wordCount[index]++;
                }
                word = strtok(NULL, " ");
            }
        }
    }

    // Sort the topWords and wordCount arrays in descending order of word count
    for (int i = 0; i < MAX_TOP_WORDS - 1; i++) {
        for (int j = i + 1; j < MAX_TOP_WORDS; j++) {
            if (wordCount[i] < wordCount[j]) {
                int tempCount = wordCount[i];
                wordCount[i] = wordCount[j];
                wordCount[j] = tempCount;

                char tempWord[MAX_NAME_LENGTH];
                strncpy(tempWord, topWords[i], MAX_NAME_LENGTH);
                strncpy(topWords[i], topWords[j], MAX_NAME_LENGTH);
                strncpy(topWords[j], tempWord, MAX_NAME_LENGTH);
            }
        }
    }

    printf("=== TOP WORDS ===\n");
    for (int i = 0; i < MAX_TOP_WORDS; i++) {
        if (wordCount[i] > 0) {
            printf("%s: %d\n", topWords[i], wordCount[i]);
        }
    }
    printf("=================\n");
}

/*
void loadUsersFromFile(UserList *userList) {
    FILE *file = fopen("users.csv", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        User newUser;
        char *token;

        // Obtener el nombre de usuario
        token = strtok(line, ",");
        strcpy(newUser.username, token);

        // Obtener la edad
        token = strtok(NULL, ",");
        newUser.age = atoi(token);

        // Obtener el correo electrónico
        token = strtok(NULL, ",");
        strcpy(newUser.email, token);

        // Obtener la ubicación
        token = strtok(NULL, ",");
        strcpy(newUser.location, token);

        // Obtener los gustos o preferencias
        token = strtok(NULL, ",");
        int preferenceIndex = 0;
        while (token != NULL && preferenceIndex < MAX_PREFERENCES) {
            strcpy(newUser.preferences[preferenceIndex], token);
            preferenceIndex++;
            token = strtok(NULL, ",");
        }

        // Añadir el nuevo usuario a la lista
        userList->users[userList->count] = newUser;
        userList->count++;
    }

    fclose(file);
}
*/
