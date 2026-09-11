# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// ========================================================
// PRINTING ARRAY
void print_array(const int *arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        // Nota: arr[i] es equivalente a escribir *(arr + i) usando aritmética de punteros
        printf("%d | ", arr[i]); 
        
    }
    printf("\n\n"); // Salto de línea al finalizar
}
// ========================================================

// ========================================================
int max(int arr[], int n) {
    int nmax = arr[0];
    for (int a = 0; a < n; a++) {
        if (arr[a] > nmax) {
            nmax = arr[a];
        }
    }
    // return the max element from the array
    return nmax;
}

// ========================================================
void RadixCountingSort(int *arr, int size, int exp) {
    int *arr_b = calloc(size, sizeof(int));
    int arr_c[10] = {0};

    for (int i = 0; i < size; i++) {
        int value = arr[i] / exp; 
        (arr_c[value % 10])++;
    }

    for (int p = 1; p < 10; p++){
        arr_c[p] = arr_c[p] + arr_c[p-1];
    }

    int idx;
    for (int r = size - 1; r >= 0;r--) {
        int value = (arr[r] / exp) % 10;
        arr_b[--arr_c[value]] = arr[r];
    }

    for (int i = 0; i < size; i++) {
        arr[i] = arr_b[i];
    }
    free(arr_b);
}
// ========================================================


void RadixSort(int *arr, int size) {
    int mx = max(arr, size);
    printf("%d\n",mx);
    for (int exp = 1; mx / exp > 0; exp *= 10) {
        RadixCountingSort(arr, size, exp);
    }
}

// ========================================================
int main()
{
    // int *array;
    // 4, 5, 23, 78, 9, 64, 47, 6, 3, 7, 15, 32
    int array[] = {4, 5, 23, 78, 9, 64, 47, 6, 3, 7, 15, 32};
    int size = sizeof(array) / sizeof(array[0]);
    // before
    printf("Before: \n");
    print_array(array, size);
    // after
    printf("After: \n");
    RadixSort(array, size);
    print_array(array, size);
    return 0;
}