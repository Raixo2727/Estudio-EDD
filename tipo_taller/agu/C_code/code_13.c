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
int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5};    
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", size);


    // inicio append
    
    arr[size] = 6;

    // fin append
    size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", size);
    elem_array(arr, size);

    
    return 0;
}
// ========================================================


