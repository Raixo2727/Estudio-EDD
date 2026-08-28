#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandomArray(int* arr, int size, int min_val, int max_val) {
    for (int i = 0; i < size; i++) {
        arr[i] = min_val + rand() % (max_val - min_val + 1);
    }
}

// Imprime el contenido del arreglo con formato legible
void printArray(const int* arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void quickSort(int* arr, int fidx, int lidx) {
    if (fidx >= lidx) {
        return;
    }
    
    int pos_pivote  = fidx + rand() % (lidx - fidx + 1);
    int pivote = arr[pos_pivote];
    arr[pos_pivote] = arr[lidx];
    arr[lidx] = pivote;

    int i = fidx;
    int j = lidx-1;

    while (i <= j) {
        while (i <= j && arr[i]< pivote) {
            i++;
        }

        while (i <= j && arr[j]> pivote) {
            j--;
        }

        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    arr[lidx] = arr[i];
    arr[i] = pivote;

    quickSort(arr, fidx, i-1);
    quickSort(arr, i+1, lidx);
}

int main(void) {
    srand((unsigned int)time(NULL));

    int size = 10;
    int arr[10];

    // Genera 10 números aleatorios entre 1 y 100
    fillRandomArray(arr, size, 1, 100);

    printf("Arreglo aleatorio generado:\n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("\nArreglo ordenado:\n");
    printArray(arr, size);

    return 0;
}
