#include <stdio.h>


void reverse_array(int *arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int helper = 0;
    helper = arr[start];
    arr[start] = arr[end];
    arr[end] = helper;

    reverse_array(arr, start+1, end-1);
}

int main(void) {
    int datos[] = {10, 20, 30, 40, 50};
    int size = sizeof(datos) / sizeof(datos[0]);

    printf("Original: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");

    reverse_array(datos, 0, size - 1);

    printf("Invertido: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");

    return 0;
}