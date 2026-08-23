#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *selection_sort(int* array_A, int n) {
    int *array_B = (int *) calloc (n, sizeof(int));
    
    // copiar todo elemento de A en B para luyego reemplazarlos
    for (int i=0; i<n; i++) {
        *(array_B + i) = *(array_A + i);}
    
    for (int i=0; i<n;i++) {
        int idx_min = i;
        for (int j=i+1; j<n; j++) {
            if (*(array_B + j) < *(array_B + idx_min)) {
                idx_min = j; 
            }}
        int temp = *(array_B + i);
        *(array_B+i) = *(array_B + idx_min);
        *(array_B + idx_min) = temp;
    }
    return array_B;
}

// Llena el arreglo con números aleatorios entre min y max
void llenar_aleatorio(int *arr, int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        *(arr + i) = min + rand() % (max - min + 1);
    }
}

// Imprime el arreglo en una sola línea
void imprimir_array(int *arr, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("]\n");
}

int main() {
    srand(time(NULL));

    int n = 10;
    int array_A[10];
    llenar_aleatorio(array_A, n, 1, 100);

    printf("Original: ");
    imprimir_array(array_A, n);
    
    int *array_B = selection_sort(array_A, n);

    printf("Ordenado: ");
    imprimir_array(array_B, n);

    free(array_B);


    return 0;
}