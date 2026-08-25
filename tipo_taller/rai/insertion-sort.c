#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * generar_aleatorios(int n, int min, int max) {
    int *arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        *(arr + i) = min + rand() % (max - min + 1);
    }

    return arr;
}

void imprimir_arreglo(const int *arr, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("]\n");
}

int * insertion_sort(int * arr_A, int n) {
    int *arr_B = (int *) calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        *(arr_B + i) = *(arr_A + i);
    }

    for (int i = 1; i < n; i++) {
        int val = *(arr_B + i);
        int idx_support = i;
        
        for (int j = i - 1; j >= 0; j--) {
            if (*(arr_B + j) > val) {
                *(arr_B + j + 1) = *(arr_B + j);
                idx_support = j;
            } else {
                break;
            }
        }
        *(arr_B + idx_support) = val;
    }

    return arr_B;
}

int main () {
    srand(time(NULL));

    int n = 10;
    
    // Asignación directa con la función generadora
    int *arr = generar_aleatorios(n, 0, 99);
    int *arr_ordenado = insertion_sort(arr, n);
    
    printf("Original: ");
    imprimir_arreglo(arr, n);

    printf("Ordenado: ");
    imprimir_arreglo(arr_ordenado, n);

    free(arr_ordenado);
    free(arr);
    return 0;
}