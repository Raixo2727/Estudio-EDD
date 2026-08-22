#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int* arreglo = calloc(n, sizeof(int));
    for (int i=0; i<n; i++) {
        arreglo[i] = 10*i;
        printf("Puesto %d: %d \n", i, arreglo[i]);
    }

    free(arreglo);
    return 0;
}
