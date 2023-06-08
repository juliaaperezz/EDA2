//
// Created by julia on 07/06/2023.
//

#include "usuarios.h"

#ifndef UNTITLED6_DICTIONARY_WORDS_H
#define UNTITLED6_DICTIONARY_WORDS_H

#endif //UNTITLED6_DICTIONARY_WORDS_H

//Estructura diccionario
typedef struct {
    char word[MAX_NAME_LENGTH];
    int count;
} WordCount;

typedef struct {
    WordCount* elements;
    int size;
    int capacity;
} Dictionary;
