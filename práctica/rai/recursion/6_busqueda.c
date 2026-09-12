#include <stdio.h>
#include <stdlib.h>

/*
 * Retorna el índice de target si existe, o -1 si no se encuentra.
 * left: índice inicial del rango de búsqueda.
 * right: índice final del rango de búsqueda.
 */
int binary_search(int *arr, int left, int right, int target) {
    if (left > right) {
        printf("El numero %d no pertenece al array", target);
        return -1;
    }

    int middle = (left + right)/2;
    if (arr[middle] == target) {
        return middle;
    } else if (target > arr[middle]) {
        return binary_search(arr, middle+1, right, target);
    } else {
        return binary_search(arr, left, middle-1, target);
    }
}

int main(void) {
    int datos[] = {3, 8, 14, 27, 33, 42, 59, 70, 85, 99};
    int size = sizeof(datos) / sizeof(datos[0]);

    int target1 = 42; // Existe (índice 5)
    int target2 = 99; // Existe en el extremo superior (índice 9)
    int target3 = 50; // No existe

    printf("Buscando %d: indice %d\n", target1, binary_search(datos, 0, size - 1, target1));
    printf("Buscando %d: indice %d\n", target2, binary_search(datos, 0, size - 1, target2));
    printf("Buscando %d: indice %d\n", target3, binary_search(datos, 0, size - 1, target3));

    return 0;
}