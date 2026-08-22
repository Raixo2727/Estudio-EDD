#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void buscar_puntos_sillas(int **matriz, int N, int M) {
    for (int i=0; i<N; i++) {
        int col_min = 0;
        for (int j=0; j<M; j++) {
            if (matriz[i][j] < matriz[i][col_min]) {
                col_min = j;
            }}
        for (int k=0; k<N; k++) {
            int candidato = 1;
            if (matriz[i][col_min] < matriz[k][col_min]) {
                
            }
        }
    
        
    }
}


int main () {
    int N;
    int M;
    printf("Ingrese la cantidad de filas N: ");
    scanf("%d", &N);
    int **matriz = (int**) calloc(N, sizeof(int*));

    prinf("\nIngrese la cantidad de columnas N: ");
    scanf("%d", &M);

    for (int i=0; i <N; i++) {
        for (int j=0; i<M; i++) {
            matriz[i][j] = rand() % 100;
        }
    }

    return 0;
}