#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
Debo implementar un algoritmo que elimina elementos duplicados de un array de K elementos. 
Debo mantener el orden tal cual pero sin los elementos repetidos.
Luego redimenzionar con realloc
*/

int eliminar_repetidos(int **arr, int k)  {
    int index = 0;
    int valor = 0;

    // **arr es un puntero de un puntero, es tal que asi arr -> *arr -> valores ints

    
    // Bucle para iterar los datos del arreglo de k elementos. 

    for (int i=0; i<k; i++) {
        valor = *(*arr + i); // tomamos el i elemento del array
        int valor_repetido = 0;

        for (int j=0; j< index; j++) {
            if (valor == *(*arr + j)) { //Los array tienen los elementos pegados en cuanto a dirección de memoria
                valor_repetido = 1;
                break;
            }}
        if (!valor_repetido) {
            *(*arr + index) = valor;
            index++;
        }
    }
    
    *arr = (int *) realloc(*arr, index*sizeof(int)); // Re asignamos el tamaño del puntero de los ints

    return index;
}

// imprimir los arrays
void imprimir_arreglo(int *arr, int n, const char *mensaje) {
    printf("%s (%d elementos):\n[ ", mensaje, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("]\n\n");
}

int main() {
    int k = 10;
    srand(time(NULL));

    int *arr= (int *) malloc(k * sizeof(int));

    for (int i=0; i<k; i++) {
        *(arr + i) = rand() % k;
    }

    imprimir_arreglo(arr, k, "Arreglo original");
    int nuevo_tam = eliminar_repetidos(&arr, k);
    imprimir_arreglo(arr, nuevo_tam, "Arreglo sin repeticiones");

    free(arr);
    return 0;
}