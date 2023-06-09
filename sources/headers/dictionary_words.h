//
// Created by julia on 07/06/2023.
//

#include "usuarios.h"

#ifndef UNTITLED6_DICTIONARY_WORDS_H
#define UNTITLED6_DICTIONARY_WORDS_H

#endif //UNTITLED6_DICTIONARY_WORDS_H

// Definición de la estructura WordCount que representa una palabra y su contador
typedef struct {
    char word[MAX_NAME_LENGTH];  // Cadena de caracteres que representa la palabra
    int count;  // Contador de la palabra
} WordCount;

// Definición de la estructura Dictionary que representa un diccionario de palabras y sus contadores
typedef struct {
    WordCount* elements;  // Puntero a un arreglo de WordCount que representa los elementos del diccionario
    int size;  // Tamaño actual del diccionario (número de elementos almacenados)
    int capacity;  // Capacidad máxima del diccionario (número máximo de elementos que puede almacenar)
} Dictionary;
