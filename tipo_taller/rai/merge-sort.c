#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int fa, int fb, int n) {
    int* arr_c =  (int *) calloc (n, sizeof(int));

    int i = fa;
    int j = fb;
    int k = 0;

    while (i<fb && j<n+fa ) {
        if (*(arr + i)<= *(arr + j) ) {
            *(arr_c + k) = *(arr + i);
            i++;
            k++;
        }
        else {
            *(arr_c + k) = *(arr + j);
            j++;
            k++;
        }
    }
    // agregar restantes
    // agregar los faltantes de a
    while (i<fb) {
        *(arr_c + k) = *(arr + i);
        i++;
        k++;
    }
    // agregar los faltantes de b
    while (j<n+fa) {
        *(arr_c + k) = *(arr + j);
        j++;
        k++;
    }
    //reemplazamos arr por arr_c
    for (int i= 0; i<n; i++) {
        *(arr + fa + i) = *(arr_c + i);
    }
    free(arr_c);
}

void mergeSort(int* arr, int fa, int n) {
    if (n <= 1) {
        return;
    }

    int n1 = n/2;
    int n2 = n - n1;
    int fb = fa + n1;

    mergeSort(arr, fa, n1);
    mergeSort(arr, fb, n2);

    merge(arr, fa, fb, n);
}

int main() {
    int arr[] = {5, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n);

    printf("Ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}