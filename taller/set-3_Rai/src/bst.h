#ifndef EDDSET_BST_H
#define EDDSET_BST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bst_node {
    int key;
    struct bst_node *parent;
    struct bst_node *left;
    struct bst_node *right;
} BstNode;

typedef struct bst {
    BstNode *root;
    size_t size;
} Bst;

/* Declaración de funciones */

BstNode *bst_node_create(int key);
int bst_node_destroy(BstNode *node);

Bst *bst_create();
void bst_destroy(Bst *bst);
void bst_print(Bst *bst, FILE *output_file);

BstNode *bst_search(Bst *bst, int key);
void bst_insert(Bst *bst, int key);
void bst_delete(Bst *bst, int key);

#endif
