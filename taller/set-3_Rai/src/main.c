#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "events.h"

static bool check_arguments(int argc, char **argv) {
    if (argc != 3) {
        printf("Uso: %s INPUT_PATH OUTPUT_PATH\n", argv[0]);
        printf("Donde:\n");
        printf("> INPUT_PATH es el path al archivo de input\n");
        printf("> OUTPUT_PATH es el path al archivo de output\n");
        exit(1);
    }
    return true;
}

int main(int argc, char **argv) {
    check_arguments(argc, argv);
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    size_t E;
    int buffer = fscanf(input_file, "%zu", &E);
    if (buffer != 1) {
        printf("Error reading number of test events");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    Bst *red_black = bst_create();

    int number = 0;
    char cmd[32];
    for (size_t i = 0; i < E; i++) {
        fscanf(input_file, "%s", cmd);

        if (!strcmp(cmd, "BALANCE")) {
            fscanf(input_file, " %d", &number);

            Bst *avl = bst_create();
            int key = 0;
            for (int j = 0; j < number; j++) {
                fscanf(input_file, "%d", &key);
                bst_insert(avl, key);
            }

            // 1. Balancear el árbol e imprimir "Se ha balanceado el ABB."
            balance(avl, output_file);

            // 2. Imprimir el árbol resultante (ya balanceado)
            bst_print(avl, output_file);

            // 3. Liberar memoria
            bst_destroy(avl);
        }

        if (!strcmp(cmd, "INSERT")) {
            fscanf(input_file, " %d", &number);
            bst_insert(red_black, number);
        }

        if (!strcmp(cmd, "DELETE")) {
            fscanf(input_file, " %d", &number);
            bst_delete(red_black, number);
        }

        if (!strcmp(cmd, "EQUIV")) {
            rbt_two_four_equiv(red_black, output_file);
        }
    }

    /* Liberamos el árbol rojo-negro */
    bst_destroy(red_black);

    /* Cerramos archivos de input y output */
    fclose(input_file);
    fclose(output_file);

    return 0;
}