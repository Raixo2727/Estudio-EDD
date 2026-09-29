#include <stdio.h>
#include <stdlib.h>

/* Definición de la estructura del nodo del Taller */
typedef struct bst_node {
    int key;
    struct bst_node *parent;
    struct bst_node *left;
    struct bst_node *right;
} BstNode;

/* Tu implementación con Head Recursion */
int bst_count_subtree_head(BstNode *node) {
    if (node == NULL) {
        return 0;
    }
    int left_count = bst_count_subtree_head(node->left);
    int right_count = bst_count_subtree_head(node->right);
    return 1 + left_count + right_count;
}

/* Helper para crear nodos de prueba */
BstNode *create_node(int key) {
    BstNode *n = (BstNode *)malloc(sizeof(BstNode));
    if (!n) return NULL;
    n->key = key;
    n->parent = NULL;
    n->left = NULL;
    n->right = NULL;
    return n;
}

/* Función para imprimir el árbol visualmente en la consola */
void print_tree(BstNode *node, int space) {
    if (node == NULL) return;

    space += 6;

    // Imprime primero el hijo derecho arriba
    print_tree(node->right, space);

    // Imprime el nodo actual con indentación
    printf("\n");
    for (int i = 6; i < space; i++) {
        printf(" ");
    }
    printf("[%d]\n", node->key);

    // Imprime el hijo izquierdo abajo
    print_tree(node->left, space);
}

/* Liberación de memoria */
void free_tree(BstNode *node) {
    if (!node) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

int main(void) {
    /*
     * Diagrama de la Sección 4 del Mini-Taller:
     *
     *          (0)  <-- root
     *         /   \
     *       (0)   (1)
     */
    BstNode *root = create_node(0);
    root->left = create_node(0);
    root->left->parent = root;
    root->right = create_node(1);
    root->right->parent = root;

    printf("=== ESTRUCTURA DEL ARBOL ===\n");
    print_tree(root, 0);
    printf("\n============================\n\n");

    // Ejecución y verificación del conteo
    int total_nodes = bst_count_subtree_head(root);
    printf("Total de nodos en el subarbol (esperado: 3): %d\n", total_nodes);

    int left_nodes = bst_count_subtree_head(root->left);
    printf("Total de nodos en hijo izquierdo (esperado: 1): %d\n", left_nodes);

    int null_nodes = bst_count_subtree_head(NULL);
    printf("Total de nodos en NULL (esperado: 0): %d\n", null_nodes);

    free_tree(root);
    return 0;
}