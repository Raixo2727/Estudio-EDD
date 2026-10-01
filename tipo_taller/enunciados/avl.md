Codigo para hacer el main de avl:

```pseudocode
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* =========================================================================
 * 1. DEFINICIÓN DE ESTRUCTURAS
 * ========================================================================= */
typedef struct avl_node {
    int key;
    int height;                 // Altura del subárbol
    struct avl_node *parent;    // Puntero al padre (NULL si es raíz)
    struct avl_node *left;      // Hijo izquierdo
    struct avl_node *right;     // Hijo derecho
} AvlNode;

typedef struct avl_tree {
    AvlNode *root;
    size_t size;
} AvlTree;

/* =========================================================================
 * 2. FUNCIONES AUXILIARES (YA RESUELTAS - NO MODIFICAR)
 * ========================================================================= */

// Crea un nodo inicializado en memoria dinámica
AvlNode* avl_node_create(int key) {
    AvlNode *node = (AvlNode*)calloc(1, sizeof(AvlNode));
    if (!node) return NULL;
    node->key = key;
    node->height = 0;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Libera recursivamente la memoria del árbol
void avl_tree_destroy(AvlNode *node) {
    if (!node) return;
    avl_tree_destroy(node->left);
    avl_tree_destroy(node->right);
    free(node);
}

// Imprime el árbol de forma rotada en consola
void print_tree_2d(AvlNode *root, int space) {
    if (!root) return;
    space += 7;
    print_tree_2d(root->right, space);
    printf("\n");
    for (int i = 7; i < space; i++) printf(" ");
    printf("[%d]\n", root->key);
    print_tree_2d(root->left, space);
}


/* =========================================================================
 * 3. SECCIÓN GUIADA: ROTATE-RIGHT (~20 min)
 * ========================================================================= */

/**
 * Realiza una rotación simple hacia la derecha sobre el nodo 'y'.
 * 
 * Parámetros:
 *  - tree: Puntero a la estructura del árbol (por si cambia la raíz general).
 *  - y:    Nodo pivote sobre el cual se realiza la rotación hacia la derecha.
 * 
 * Retorno:
 *  - Debe retornar el nodo 'x' (hijo izquierdo original de y), que pasa a ser
 *    la nueva raíz de este subárbol.
 */
AvlNode* avl_rotate_right(AvlTree *tree, AvlNode *y) {
    // TODO: Implementa aquí el pseudocódigo de la Sección A
    // Recuerda actualizar:
    // 1. x = y->left y el subárbol central T2 = x->right
    // 2. Conectar T2 a la izquierda de y (y actualizar T2->parent si no es NULL)
    // 3. Conectar x con el padre original de y (y actualizar tree->root si y era la raíz)
    // 4. Conectar y a la derecha de x (y asignar y->parent = x)
    
    return NULL; // Reemplazar por tu retorno
}


/* =========================================================================
 * 4. SECCIÓN AUTÓNOMA: FIND-UNBALANCED (~40 min)
 * ========================================================================= */

/**
 * Calcula de manera ascendente la altura del subárbol y retorna el nodo
 * desbalanceado (|BF| > 1) más profundo (bottom-up).
 * 
 * Parámetros:
 *  - node:   Nodo actual en la recursión.
 *  - height: Puntero por referencia para guardar la altura calculada de 'node'.
 *            (Convención: subárbol NULL tiene altura -1; nodo hoja tiene altura 0).
 * 
 * Retorno:
 *  - Puntero al primer AvlNode desbalanceado (|BF| > 1) que se detecte.
 *  - Si todo el subárbol está balanceado, retorna NULL.
 */
AvlNode* avl_find_unbalanced(AvlNode *node, int *height) {
    // TODO: Tu código aquí
    // 1. Caso base: si node == NULL, ¿cuánto vale *height y qué retornas?
    // 2. Variables locales para alturas de hijos: int left_h, right_h;
    // 3. Llamadas recursivas a izquierda y derecha.
    // 4. Si izquierda o derecha ya detectaron desbalance, propágalo retornándolo.
    // 5. Calcula la altura del nodo actual: *height = 1 + max(left_h, right_h).
    // 6. Calcula el factor de balance: BF = left_h - right_h.
    //    Si |BF| > 1, retorna 'node'. En caso contrario, retorna NULL.
    
    return NULL; // Reemplazar por tu retorno
}


/* =========================================================================
 * 5. SUITE DE PRUEBAS LOCALES (MAIN)
 * ========================================================================= */
int main(void) {
    printf("=====================================================\n");
    printf("           TALLER DE PRÁCTICA: ÁRBOLES AVL            \n");
    printf("=====================================================\n\n");

    /* ---------------------------------------------------------------------
     * TEST 1: ROTATE-RIGHT
     * Árbol de prueba:
     *          (30)                  (20)
     *         /                     /    \
     *       (20)     == ROT =>    (10)   (30)
     *      /    \                        /
     *    (10)   (25)                   (25)
     * --------------------------------------------------------------------- */
    printf("--- [TEST 1] Probando avl_rotate_right ---\n");
    AvlTree tree1;
    tree1.size = 4;
    
    AvlNode *n30 = avl_node_create(30);
    AvlNode *n20 = avl_node_create(20);
    AvlNode *n10 = avl_node_create(10);
    AvlNode *n25 = avl_node_create(25);

    // Conexiones iniciales
    tree1.root = n30;
    n30->left = n20;  n20->parent = n30;
    n20->left = n10;  n10->parent = n20;
    n20->right = n25; n25->parent = n20;

    printf("Árbol ANTES de rotar a la derecha sobre el nodo [30]:\n");
    print_tree_2d(tree1.root, 0);

    AvlNode *new_subroot = avl_rotate_right(&tree1, n30);

    printf("\nÁrbol DESPUÉS de rotar:\n");
    print_tree_2d(tree1.root, 0);

    if (new_subroot && new_subroot->key == 20 && tree1.root == new_subroot &&
        n20->right == n30 && n30->left == n25 && n25->parent == n30) {
        printf("\n=> TEST 1: ROTATE-RIGHT FUNCIONA CORRECTAMENTE!\n\n");
    } else {
        printf("\n=> TEST 1: Pendiente o con errores en punteros.\n\n");
    }
    avl_tree_destroy(tree1.root);


    /* ---------------------------------------------------------------------
     * TEST 2: FIND-UNBALANCED (Detección de nodo desbalanceado)
     * Árbol de prueba:
     *          (10)
     *            \
     *            (20)
     *              \
     *              (30)   <-- Desbalance tipo R-R en nodo 10 (BF = -1 - 1 = -2)
     * --------------------------------------------------------------------- */
    printf("--- [TEST 2] Probando avl_find_unbalanced (Caso Desbalanceado) ---\n");
    AvlNode *m10 = avl_node_create(10);
    AvlNode *m20 = avl_node_create(20);
    AvlNode *m30 = avl_node_create(30);

    m10->right = m20; m20->parent = m10;
    m20->right = m30; m30->parent = m20;

    int calc_height = 0;
    AvlNode *unbalanced = avl_find_unbalanced(m10, &calc_height);

    if (unbalanced != NULL) {
        printf("Nodo desbalanceado detectado: [%d] (Esperado: 10)\n", unbalanced->key);
        printf("Altura calculada del subárbol: %d (Esperado: 2)\n", calc_height);
        if (unbalanced->key == 10 && calc_height == 2) {
            printf("=> TEST 2: DETECCIÓN CORRECTA!\n\n");
        }
    } else {
        printf("=> TEST 2: Pendiente o retornó NULL (no detectó desbalance).\n\n");
    }
    avl_tree_destroy(m10);


    /* ---------------------------------------------------------------------
     * TEST 3: FIND-UNBALANCED (Caso Balanceado)
     *          (20)
     *         /    \
     *       (10)   (30)
     * --------------------------------------------------------------------- */
    printf("--- [TEST 3] Probando avl_find_unbalanced (Caso Balanceado) ---\n");
    AvlNode *b20 = avl_node_create(20);
    AvlNode *b10 = avl_node_create(10);
    AvlNode *b30 = avl_node_create(30);

    b20->left = b10;  b10->parent = b20;
    b20->right = b30; b30->parent = b20;

    calc_height = 0;
    AvlNode *res_bal = avl_find_unbalanced(b20, &calc_height);

    if (res_bal == NULL && calc_height == 1) {
        printf("Árbol correctamente evaluado como balanceado (retornó NULL, altura 1).\n");
        printf("=> TEST 3: PASÓ EXITOSAMENTE!\n\n");
    } else {
        printf("=> TEST 3: Falló, detectó desbalance en nodo inexistente o altura errónea.\n\n");
    }
    avl_tree_destroy(b20);

    return 0;
}

```