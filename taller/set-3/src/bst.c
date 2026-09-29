#include "bst.h"

/*
 * Hola, estimado/a estudiante! :D
 *
 * A continuación te dejamos una implementación de ABBs basada
 * en la solución del set pasado, para que lo puedas usar como
 * base para el árbol AVL y Rojo-Negro.
 *
 * Cabe destacar que es MUY probable que debas cambiar el código
 * que se encuentra en main.c, dado que dependerá de tu implementación
 * el cómo se hagan las llamadas a las funciones necesarias. De todos
 * modos, dejamos el código en main lo más completo posible para que
 * no sea tan complejo realizar los cambios necesarios.
 *
 * Mucho éxito!
 */

BstNode *bst_node_create(int key) {
    BstNode *new_node = malloc(sizeof(BstNode));

    new_node->key = key;

    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int bst_node_destroy(BstNode *node) {
    int key = node->key;
    free(node);

    return key;
}

Bst *bst_create() {
    Bst *new_bst = malloc(sizeof(Bst));

    new_bst->root = NULL;
    new_bst->size = 0;

    return new_bst;
}

void bst_destroy(Bst *bst) {
    size_t capacity = (bst->size == 0) ? 1 : bst->size;
    BstNode *stack[capacity];

    stack[0] = bst->root;
    size_t size = 1;

    BstNode *current_node = bst->root;
    while (size > 0 && current_node != NULL) {
        current_node = stack[size - 1];
        size--;

        if (current_node->left != NULL) {
            stack[size] = current_node->left;
            size++;
        }

        if (current_node->right != NULL) {
            stack[size] = current_node->right;
            size++;
        }

        bst_node_destroy(current_node);
    }

    free(bst);

    return;
}

static void bst_rec_tree_print(
    BstNode *node,
    char *stack,
    size_t stack_idx,
    char parent,
    const char *left_sep,
    const char *right_sep,
    FILE *output_file
) {
    if (node->parent != NULL) {
        fprintf(output_file, "         ");
    }

    for (size_t i = 0; i < stack_idx; i++) {
        if (stack[i] == 'l') {
            fprintf(output_file, "%s", left_sep);
        } else if (stack[i] == 'r') {
            fprintf(output_file, "%s", right_sep);
        }
    }

    if (parent == 'l') {
        stack[stack_idx] = 'l';
        fprintf(output_file, "└─");
    } else if (parent == 'r') {
        stack[stack_idx] = 'r';
        fprintf(output_file, "├─");
    }

    fprintf(output_file, "[%d]\n", node->key);

    if (node->right != NULL) {
        bst_rec_tree_print(node->right, stack, stack_idx + 1, 'r', left_sep, right_sep, output_file);
    }

    if (node->left != NULL) {
        bst_rec_tree_print(node->left, stack, stack_idx + 1, 'l', left_sep, right_sep, output_file);
    }
}

void bst_print(Bst *bst, FILE *output_file) {
    if (output_file == NULL) {
        output_file = stdout;
    }

    fprintf(output_file, "Bst\n");
    fprintf(output_file, "> root : ");
    if (bst->size == 0) {
        fprintf(output_file, "(nil)\n");
    } else {
        fprintf(output_file, "%d\n", bst->root->key);
    }
    fprintf(output_file, "> size : %zu\n", bst->size);
    fprintf(output_file, "> log  : ");

    if (bst->size == 0) {
        fprintf(output_file, "\n");
        return;
    }

    char stack[64];
    for (size_t i = 0; i < 64; i++) {
        stack[i] = '\0';
    }
    const char *left_sep = "   ";
    const char *right_sep = "│  ";
    bst_rec_tree_print(bst->root, stack, 0, 't', left_sep, right_sep, output_file);

    return;
}

static BstNode *bst_successor(BstNode *node) {
    if (node == NULL) return NULL;

    BstNode *current_node = node;

    if (node->right != NULL) {
        current_node = current_node->right;
        while (current_node->left != NULL) {
            current_node = current_node->left;
        }

        return current_node;
    }

    BstNode *parent_node = node->parent;
    while (parent_node != NULL && current_node == parent_node->right) {
        current_node = parent_node;
        parent_node = parent_node->parent;
    }

    return parent_node;
}

static void bst_substitute_nodes(Bst* bst, BstNode *old_node, BstNode *substitute) {
    if (bst == NULL || old_node == NULL) return;

    if (old_node->parent == NULL) {
        bst->root = substitute;
    } else if (old_node == old_node->parent->left) {
        old_node->parent->left = substitute;
    } else {
        old_node->parent->right = substitute;
    }

    if (substitute != NULL) {
        substitute->parent = old_node->parent;
    }

    return;
}

BstNode *bst_search(Bst *bst, int key) {
    if (bst == NULL || bst->size == 0) {
        return NULL;
    }

    bool found = false;
    BstNode *current_node = bst->root;
    while (!found && current_node != NULL) {
        if (current_node->key == key) {
            found = true;
            continue;
        }

        if (key < current_node->key) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }

    if (!found) {
        return NULL;
    }

    return current_node;
}

void bst_insert(Bst *bst, int key) {
    if (bst == NULL) return;

    BstNode *parent_node = NULL;
    BstNode *current_node = bst->root;
    while (current_node != NULL) {
        parent_node = current_node;

        if (key < current_node->key) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }

    BstNode *new_node = bst_node_create(key);
    new_node->parent = parent_node;
    bst->size++;

    if (parent_node == NULL) {
        bst->root = new_node;
        return;
    }

    if (key < parent_node->key) {
        parent_node->left = new_node;
    } else {
        parent_node->right = new_node;
    }

    return;
}

void bst_delete(Bst *bst, int key) {
    if (bst == NULL) {
        return;
    }

    BstNode *target_node = bst_search(bst, key);
    if (target_node == NULL) {
        return;
    }

    if (target_node->left == NULL) {
        bst_substitute_nodes(bst, target_node, target_node->right);
    } else if (target_node->right == NULL) {
        bst_substitute_nodes(bst, target_node, target_node->left);
    } else {
        BstNode *target_successor = bst_successor(target_node);
        if (target_successor == NULL) {
            return;
        }

        if (target_successor->parent != target_node) {
            bst_substitute_nodes(bst, target_successor, target_successor->right);
            target_successor->right = target_node->right;
            target_successor->right->parent = target_successor;
        }

        bst_substitute_nodes(bst, target_node, target_successor);
        target_successor->left = target_node->left;
        target_successor->left->parent = target_successor;
    }

    bst_node_destroy(target_node);
    bst->size--;

    return;
}
