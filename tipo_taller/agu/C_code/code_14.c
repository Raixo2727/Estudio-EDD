# include <stdio.h>
# include <stdlib.h>

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

// ========================================================
void ext (int arr[], int siz, int elem) 
{
    int new_arr[siz + 1];
    for (int i=0; i < siz;i++) 
    {
        new_arr[i] = arr[i];
    }
    new_arr[siz] = elem;


    int size = sizeof(new_arr) / sizeof(new_arr[0]);
    elem_array(new_arr, size);
}
// ========================================================

// ========================================================
int main(int argc, char const *argv[])
{
    int arr[] = {1, 4, 15, 6, 7, 8, 8, 4, 6, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int num = 8;
    ext(arr, size, num);

    
    return 0;
}
// ========================================================