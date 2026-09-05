#include "events.h"

/*
 * Hola, estimado/a estudiante! :D
 *
 * Este es el archivo donde deberás trabajar principalmente.
 * Para resolver este set de ejercicios, debes completar cada una
 * de las funciones que están definidas más abajo según lo indicado
 * en el enunciado. De todos modos, podría ser interesante analizar
 * cómo está construido el archivo main.c, para entender cómo se
 * llaman y conectan las funciones en este archivo desde main.
 *
 * Siéntete libre de modificar este código base como gustes. A veces
 * la forma en que resolvemos el problema no es la misma, pero
 * mientras lleguen al mismo resultado está bien. Cabe destacar que
 * cambiar este código base puede involucrar cambiar un poco el
 * archivo main.c también.
 *
 * Mucho éxito!
 */

void dictsort(char **words, size_t word_count, size_t word_length, FILE *output_file) {
    // TODO Parece que no teiene nada que ver con la ABB
}

BstNode *bst_search(Bst *bst, int key, FILE *output_file) {
    BstNode* curr = bst -> root;

    while (curr != NULL && (curr -> key) != key) {
        if (key < (curr -> key)) {
            curr = curr -> left;
        } else {
            curr = curr -> right;
        }
    }

    if (curr == NULL) {
        fprintf(output_file, "No se ha encontrado el numero %d en el ABB.\n", key);
        return NULL;
    }

    fprintf(output_file, "Se ha encontrado el numero %d en el ABB.\n", key);
    return curr;
}

void bst_insert(Bst *bst, int key, FILE *output_file) {
    BstNode *new_node = calloc(1, sizeof(BstNode));
    new_node -> key = key;
    new_node -> parent = NULL;
    new_node -> left = NULL;
    new_node -> right = NULL;

    BstNode* curr = bst -> root;
    BstNode* previous = NULL;

    if (curr == NULL) {
        bst -> root = new_node;
        bst -> size++;
        fprintf(output_file, "Se ha insertado el numero %d en el ABB.\n", key);
        return;
    }

    
    while (curr != NULL) {
        if ((new_node -> key) < (curr -> key)) {
            previous = curr;
            curr = curr -> left;
        } else {
            previous = curr;
            curr = curr -> right;
        }
    }

    if ((new_node -> key) < (previous -> key)) {
        previous -> left = new_node;
    } else {
        previous -> right = new_node;
    }
    new_node -> parent = previous;
    bst -> size++;
    
    fprintf(output_file, "Se ha insertado el numero %d en el ABB.\n", key);

    return;
}

void bst_delete(Bst *bst, int key, FILE *output_file) {
    EddError err = EDD_NOERR;

    // TODO
}

void bst_two_sum(Bst *bst, int sum, FILE *output_file) {
    // TODO
}
