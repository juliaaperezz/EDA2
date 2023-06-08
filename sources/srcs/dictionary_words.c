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


void initializeDictionary(Dictionary* dict, int capacity) {
    dict->elements = (WordCount*)malloc(capacity * sizeof(WordCount));
    dict->size = 0;
    dict->capacity = capacity;
}

void addWord(Dictionary* dict, const char* word) {
    for (int i = 0; i < dict->size; i++) {
        WordCount* wc = &(dict->elements[i]);
        if (strcmp(wc->word, word) == 0) {
            wc->count++;
            return;
        }
    }

    if (dict->size >= dict->capacity) {
        printf("Error: Full dictionary.\n");
        return;
    }

    WordCount* wc = &(dict->elements[dict->size]);
    strncpy(wc->word, word, sizeof(wc->word)-1);
    wc->word[sizeof(wc->word)-1] = '\0';
    wc->count = 1;

    dict->size++;
}

int compareWordCounts(const void* a, const void* b) {
    const WordCount* wc1 = (const WordCount*)a;
    const WordCount* wc2 = (const WordCount*)b;
    return wc2->count - wc1->count;
}

void destroyDictionary(Dictionary* dict){
    free(dict->elements);
    dict->size = 0;
    dict->capacity = 0;
}


void displayTopWords(UserList* userList) {
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
