#include <stdio.h>
#include <stdlib.h>

bool find_element(int *arr, int size, int target) {
    if (size == 0) {
        return false;
    }
    if (arr[0] == target) {
        return true;
    }

    return find_element(arr + 1, size-1, target);
}

int main(void) {
    int ids[] = {104, 255, 301, 412, 599};
    // Calculamos la cantidad de elementos dividiendo el tamaño total en bytes 
    // por el tamaño en bytes de un solo elemento
    int size = sizeof(ids) / sizeof(ids[0]); 

    int target1 = 301;
    int target2 = 999;

    if (find_element(ids, size, target1)) {
        printf("El ID %d SI tiene acceso.\n", target1);
    } else {
        printf("El ID %d NO tiene acceso.\n", target1);
    }

    if (find_element(ids, size, target2)) {
        printf("El ID %d SI tiene acceso.\n", target2);
    } else {
        printf("El ID %d NO tiene acceso.\n", target2);
    }

    return 0;
}