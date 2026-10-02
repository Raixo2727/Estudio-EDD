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

void llenador_array(BstNode** arr, BstNode* node, int* index)  {
    // recorremos el arreglo, si llegamos a null nos devolvemos
    if (node == NULL) {
        return;
    }

    // recorremos full izquierda y derecha, recorriendo el array tambien
    llenador_array(arr, node -> left, index);
    arr[*index] = node;
    (*index)++;
    llenador_array(arr, node-> right, index);
}

BstNode* armar_avl(BstNode** arr, int inicio, int final, BstNode* padre) {
    // Si los indices coinciden pos matar
    if (inicio > final) {
        return NULL;
    }
    
    // Escogemos el pivote del medio que siempre será la mitad
    int pivote = inicio + (final - inicio)/2;

    // re asignamos los punteros
    arr[pivote] -> parent = padre;
    arr[pivote] -> left = armar_avl(arr, inicio, pivote-1, arr[pivote]);
    arr[pivote] -> right = armar_avl(arr, pivote+1, final, arr[pivote]);

    return arr[pivote];
}


void balance(Bst* tree, FILE* output_file) {
    BstNode** arr = calloc(tree -> size, sizeof(BstNode*)); 
    int index = 0;
    llenador_array(arr, tree->root, &index);

    int inicio = 0;
    int final = tree->size -1;
    int nueva_root = inicio + (final - inicio)/2;


    armar_avl(arr, inicio, final, NULL);
    tree -> root = arr[nueva_root];

    fprintf(output_file, "Se ha balanceado el ABB.\n");

    free(arr);
}


void rbt_two_four_equiv(Bst *rbt, FILE *output_file) {
    // TODO
}
