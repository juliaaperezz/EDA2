//
// Created by julia on 07/06/2023.
//

#include "../headers/dictionary_words.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeDictionary(Dictionary* dict, int capacity);
void addWord(Dictionary* dict, const char* word);
int compareWordCounts(const void* a, const void* b);
void destroyDictionary(Dictionary* dict);
void displayTopWords(UserList* userList);

// Función para inicializar un diccionario
void initializeDictionary(Dictionary* dict, int capacity) {
    // Asigna memoria para los elementos del diccionario
    dict->elements = (WordCount*)malloc(capacity * sizeof(WordCount));
    dict->size = 0;
    dict->capacity = capacity;
}

//Función para añadir una palabra al diccionario
void addWord(Dictionary* dict, const char* word) {
    // Busca si la palabra ya existe en el diccionario
    for (int i = 0; i < dict->size; i++) {
        WordCount* wc = &(dict->elements[i]);
        if (strcmp(wc->word, word) == 0) {
            wc->count++;  // Incrementa el contador si la palabra ya existe
            return;
        }
    }

    // Si la palabra no existe en el diccionario
    if (dict->size >= dict->capacity) {
        printf("Error: Full dictionary.\n");  // Mensaje de error si el diccionario está lleno
        return;
    }

    //Añadimos el elemento al diccionario
    WordCount* wc = &(dict->elements[dict->size]);
    strncpy(wc->word, word, sizeof(wc->word)-1); // Copia la palabra al diccionario
    wc->word[sizeof(wc->word)-1] = '\0';  // Asegura que la cadena tenga terminación nula
    wc->count = 1; // Establece el contador en 1

    dict->size++;  // Incrementa el tamaño del diccionario
}

//Función para ordenar los elementos del diccionario de forma descendente
int compareWordCounts(const void* a, const void* b) {
    // Función de comparación utilizada para ordenar los elementos del diccionario por contador
    const WordCount* wc1 = (const WordCount*)a;
    const WordCount* wc2 = (const WordCount*)b;
    return wc2->count - wc1->count;  // Orden descendente según el contador
}

//Función para eliminar diccionario
void destroyDictionary(Dictionary* dict){
    free(dict->elements);  // Libera la memoria asignada para los elementos del diccionario
    dict->size = 0;  // Restablece el tamaño a cero
    dict->capacity = 0;  // Restablece la capacidad a cero
}

//Funcion para mostraar por pantalla las top 10 palabras más usadas por los usuarios en sus publicaciones
void displayTopWords(UserList* userList) {
    //Declaración e inicialización del diccionario
    Dictionary dict;
    initializeDictionary(&dict, MAX_USERS * MAX_POST_LENGTH);

    // Recorrer la lista de usuarios y contar las palabras en sus posts
    for (int i = 0; i < userList->count; i++) {
        User* user = &(userList->users[i]);

        for (int j = 0; j < user->postCount; j++) {
            char* post = user->posts[j];
            char* word = strtok(post, " ");

            while (word != NULL) {
                addWord(&dict, word);
                word = strtok(NULL, " ");
            }
        }
    }

    // Ordenar las palabras por frecuencia (orden descendente)
    qsort(dict.elements, dict.size, sizeof(WordCount), compareWordCounts);

    // Imprimir las 10 palabras más usadas
    int printCount = dict.size < MAX_TOP_WORDS ? dict.size : MAX_TOP_WORDS;
    printf("The %d top words most used in posts are:\n", printCount);
    for (int i = 0; i < printCount; i++) {
        printf("%s: %d\n", dict.elements[i].word, dict.elements[i].count);
    }

    // Liberar la memoria del diccionario
    destroyDictionary(&dict);
}
