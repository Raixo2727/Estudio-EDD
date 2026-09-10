# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>


void partition(int *arr, int i, int f) {

    int m = calloc(f-1, sizeof(int));
    int n = calloc(f-1, sizeof(int));

    int *mi = 0;
    int *ni = 0;

    for (int k = i; k < f; k++) {

        if (arr[f] > arr[k]) {
            m[mi] = arr[k];
            (*mi)++;
        }
        else if (arr[f] < arr[k]){
            n[ni] = arr[k];
            (*ni)++;
        }
            
        }
        
    for (int x = i; i < f, x++) {
        
    }
}

// ========================================================
// PRINTING ARRAY
void elem_array(const int *arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        // Nota: arr[i] es equivalente a escribir *(arr + i) usando aritmética de punteros
        printf("%d | ", arr[i]); 
    }
    printf("\n"); // Salto de línea al finalizar
}
// ========================================================

int main()
{
    int *array;
    array[0] = 1;
    array[1] = 2;

    elem_array(array, 2);

    return 0;
}