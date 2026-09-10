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

    BstNode* find_node = bst -> root;
    BstNode* parent = NULL;
    while (find_node != NULL && key != (find_node -> key)) {
        if (key<(find_node -> key)) {
            parent = find_node;
            find_node = find_node -> left;
        } else {
            parent = find_node;
            find_node = find_node -> right;
        }
    }

    if (find_node == NULL) {
        fprintf(output_file, "No se pudo eliminar el numero %d en el ABB.\n", key);
        return;
    }

    // EL nodo a eliminar no tiene hijos
    if (find_node -> left == NULL && find_node -> right == NULL) {
        if (parent == NULL) {
            bst -> root = NULL;
        }
        else if (parent -> left == find_node) {
            parent -> left = NULL;
        } else {
            parent -> right = NULL;
        }

        bst_node_destroy(&err, find_node);
        bst->size--;
        fprintf(output_file, "Se ha eliminado el numero %d en el ABB.\n", key);
        return;
    }

    // El nodo tiene 1 hijo
    if (find_node -> right == NULL) {
        if (parent == NULL) {
            bst -> root = find_node -> left;
        } else if (parent -> left == find_node) {
            parent -> left = find_node->left;
        } else {
            parent -> right = find_node -> left;
        }

        find_node->left->parent = parent;

        bst_node_destroy(&err, find_node);
        bst->size--;
        fprintf(output_file, "Se ha eliminado el numero %d en el ABB.\n", key);
        return;

    } else if (find_node -> left == NULL) {
        if (parent == NULL) {
            bst -> root = find_node -> right;
        } else if (parent -> left == find_node) {
            parent -> left = find_node->right;
        } else {
            parent -> right = find_node -> right;
        }

        find_node->right->parent = parent;

        bst_node_destroy(&err, find_node);
        bst->size--;
        fprintf(output_file, "Se ha eliminado el numero %d en el ABB.\n", key);
        return;
    }

    // El nodo tiene 2 hijos
    BstNode* replace = find_node -> right;
    BstNode* replace_parent = find_node;
    while(replace -> left != NULL) {
        replace_parent = replace;
        replace = replace -> left;
    }

    find_node -> key = replace -> key;

    if (replace_parent->left == replace) {
        replace_parent->left = replace->right;
    } else {
        replace_parent->right = replace->right;
    }
    
    if (replace->right != NULL) {
        replace->right->parent = replace_parent;
    }

    // Destruimos el nodo sustituto (no find_node)
    bst_node_destroy(&err, replace);
    bst->size--;
    fprintf(output_file, "Se ha eliminado el numero %d en el ABB.\n", key);
    return;
}

void bst_two_sum(Bst *bst, int sum, FILE *output_file) {
    // TODO
}
