#include "events.h"

/*
 * Hola, estimado/a estudiante! :D
 *
 * En este archivo se encuentra la definición
 * para la función del evento EQUIV. Cabe destacar
 * que se espera que la impresión sea de la raíz
 * hacia las hojas y de izquierda a derecha.
 *
 * Mucho éxito!
 */

// balance

void llenador(BstNode** arr, int* index, BstNode* node ) {
    if (node == NULL) {
        return;
    }

    llenador(arr, index, node -> left);
    arr[*index] = node;
    (*index)++;
    llenador(arr, index, node->right);
}

BstNode* armador(BstNode** arr, int inicio, int final, BstNode* padre) {
    if (inicio > final) {
        return NULL;
    }
    
    int pivote = inicio + (final - inicio) / 2;

    arr[pivote] -> parent = padre;
    arr [pivote] -> left = armador(arr, inicio, pivote-1, arr[pivote]);
    arr [pivote] -> right = armador(arr, pivote+1, final, arr[pivote]);

    return arr[pivote];
}


void balance(Bst* tree, FILE* output_file) {
    // creamos un arreglo para almacenar punteros a los nodos
    if (!tree || tree->size == 0) {
        return;
    }

    BstNode** arr = calloc(tree -> size, sizeof(BstNode*));
    int index = 0;
    llenador(arr, &index, tree -> root);

    int inicio = 0;
    int final = tree -> size - 1;
    tree -> root = armador(arr, inicio, final, NULL);

    fprintf(output_file, "Se ha balanceado el ABB.\n");
    // liberamos la memoria del arreglo
    free(arr);
};

void rbt_two_four_equiv(Bst *rbt, FILE *output_file) {
    // TODO
}
