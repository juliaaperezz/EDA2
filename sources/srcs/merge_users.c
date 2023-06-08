
#include "../headers/merge_users.h"
#include "../headers/posts.h"
#include "../headers/main+menu.h"

void merge(User* arr, int left, int middle, int right);
void mergeSort(User* arr, int left, int right);


// Función de mezcla para MergeSort
void merge(User* arr, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    User L[n1], R[n2];

    // Copiar elementos a los subarreglos izquierdo (L) y derecho (R)
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;  // Índice para el subarreglo izquierdo (L)
    j = 0;   // Índice para el subarreglo derecho (R)
    k = left;   // Índice para el arreglo principal (arr)

    // Mezclar y ordenar los elementos de L y R en arr
    while (i < n1 && j < n2) {
        if (L[i].age <= R[j].age) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L (si hay alguno)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R (si hay alguno)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función MergeSort para ordenar los usuarios por edad
void mergeSort(User* arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Ordenar el subarreglo izquierdo
        mergeSort(arr, left, middle);

        // Ordenar el subarreglo derecho
        mergeSort(arr, middle + 1, right);

        // Mezclar los subarreglos ordenados
        merge(arr, left, middle, right);
    }
}
