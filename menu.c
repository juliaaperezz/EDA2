//
// Created by Carla Núñez Viñas on 9/5/23.
//

#define MAX_INTERESTS 5
#define MAX_LENGHT 50
#include <stdio.h>
#include <string.h>
#define INVALID_OPTION -1
#define OPTION_NEW 1
#define OPTION_EXIST 2
#define OPTION_OPERATE 3
#define OPTION_QUIT 0

typedef struct{
    char username[MAX_LENGHT];
    int age;
    char mail[MAX_LENGHT];
    char location[MAX_LENGHT];
    char interests[MAX_INTERESTS][MAX_LENGHT];
}User;

void menu_as_user() //en caso que cuando se muestra el menu se seleccione Operate as a user

void show_menu(){
    printf("Welcome to our social media!\n");
    printf("What do you want to do?\n");
    int option = INVALID_OPTION;
    while (option != OPTION_QUIT) {

        printf("\n");
        printf( "%d. Insert a new user\n",  OPTION_NEW);
        printf( "%d. List the existing users\n",  OPTION_EXIST);
        printf( "%d. Operate as a user\n",  OPTION_OPERATE);
        printf( "%d. Quit\n", OPTION_QUIT);
        option = read_int_option("Choose an option: \n"); //pendiente

        if (option == OPTION_QUIT) {
            // Do nothing, it will exit the loop

        } else if (option == OPTION_NEW) {  //new user


        } else if (option == OPTION_EXIST) {  //list users


        } else if (option == OPTION_OPERATE) {  //operate as a user


        } else {
            printf("Invalid option!\n");
        }
    }
}