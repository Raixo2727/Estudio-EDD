#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int numero;
    struct nodo *siguiente;
} Nodo;

int main() {
    struct nodo *uno = calloc(1, sizeof(struct nodo));
    struct nodo *dos = calloc(1, sizeof(struct nodo));

    uno -> numero = 50;
    dos -> numero = 100;

    uno -> siguiente = dos;
    dos -> siguiente = NULL;

    printf("El número del nodo 2 es: %d \n", uno->siguiente->numero);
    free(uno);
    free(dos);
    return 0;
}