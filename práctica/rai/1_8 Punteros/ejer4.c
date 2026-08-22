#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int numero;
    struct nodo *siguiente;
} Nodo;

int main() {
    struct nodo *uno = calloc(1, sizeof(struct nodo));
    struct nodo *dos = calloc(1, sizeof(struct nodo));
    struct nodo *tres = calloc(1, sizeof(struct nodo));

    uno -> numero = 10;
    dos -> numero = 20;
    tres -> numero = 30;


    uno -> siguiente = dos;
    dos -> siguiente = tres;
    tres -> siguiente = NULL;

    Nodo *actual = uno;
    while (actual != NULL) {
        printf("El número del puntero %p es : %d\n", actual, actual->numero);
        actual = actual->siguiente;
    }

    free(uno);
    free(dos);
    free(tres);
    return 0;
}

