# include <stdio.h>
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
