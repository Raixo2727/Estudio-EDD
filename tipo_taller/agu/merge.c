#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int minim(int *array, int n) 
{
    int min = 0; // Se asume que el menor está en el índice 0 inicialmente
    for (int i = 0; i < n; i++) 
    {
        if (*(array + i) < *(array + min)) 
        {
            min = i; // Guardamos el índice del nuevo número menor
        }
    }
    return *(array + min); // Retornamos el VALOR, no el índice
}

int main()
{
    // Declaración correcta de un arreglo de enteros
    int array_A[4] = {12, 15, 9, 65};
    int array_B[4] = {45, 54, 43, 23};
    
    // Pasamos el arreglo simplemente usando su nombre
    int f = minim(array_B, 4);

    printf("El valor minimo es: %d\n", f);

    return 0;
}




