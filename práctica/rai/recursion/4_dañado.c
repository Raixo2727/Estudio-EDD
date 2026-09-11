#include <stdio.h>

/*
 * Retorna la cantidad de elementos menores a 0 en el arreglo.
 */
int count_damaged_packages(int *arr, int size) {
    if (size == 0) {
        return 0;
    }

    if (arr[0] >= 0) {
        return 0 + count_damaged_packages(arr + 1, size-1);
    } else {
        return 1 + count_damaged_packages(arr + 1, size-1);
    }
}

int main(void) {
    // Array de prueba: contiene 3 números negativos (-5, -12, -1)
    int paquetes[] = {120, -5, 340, -12, 0, 89, -1};
    int size = sizeof(paquetes) / sizeof(paquetes[0]);

    int total_danados = count_damaged_packages(paquetes, size);

    printf("Total de paquetes en cinta: %d\n", size);
    printf("Paquetes danados encontrados: %d\n", total_danados);

    return 0;
}