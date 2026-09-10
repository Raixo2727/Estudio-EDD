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

void CountingSort(int *arr, int size) {
    int *arr_b = calloc(size, sizeof(int));
    int k = max(arr, size)+1;
    int *arr_c = calloc(k, sizeof(int));

    print_array(arr_c, k);

    for (int i = 0; i < size; i++) {
        int value = arr[i]; 
        (arr_c[value])++;
    }

    printf("1er paso: \n");
    print_array(arr_c, k);

    // sum of the last value
    for (int p = 1; p < k; p++){
        arr_c[p] = arr_c[p] + arr_c[p-1];
    }
    // 2do paso
    printf("2do paso (suma de p-1): \n");
    print_array(arr, size);
    printf("----\n");
    print_array(arr_c, k);

    int idx;
    for (int r = size - 1; r >= 0;r--) {
        int value = arr[r];
        idx = arr_c[arr[r]]-1;
        arr_b[idx]= value;
        arr_c[arr[r]]--;
    }
    // 3ER paso
    printf("3ER paso : \n");
    qprint_array(arr_b, size);

    for (int i = 0; i < size; i++) {
        arr[i] = arr_b[i];
    }

    free(arr_b);
    free(arr_c);

    
}
// ========================================================

// ========================================================
int main()
{
    // int *array;
    // 4, 5, 23, 78, 9, 64, 47, 6, 3, 7, 15, 32
    int array[] = {4, 5, 23, 78, 9, 64, 47, 6, 3, 7, 15, 32};
    int size = sizeof(array) / sizeof(array[0]);

    int maxi = max(array, size);
    // max value
    
    printf("%d\n", maxi);
    // before
    printf("Antes \n:");
    print_array(array, size);
    // after
    printf("Todavia \n:");
    CountingSort(array, size);

    return 0;
}