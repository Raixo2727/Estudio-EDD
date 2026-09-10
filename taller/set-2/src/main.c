#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "events.h"
#include "libedd/libedd_bst.h"

/*
 * Puedes setear la siguiente variable a 'true'
 * para activar los mensajes de debugging de LibEDD.
 */
bool EDD_DEBUG = false;

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
        return 1;
    }

    Bst *bst = bst_create(NULL);

    EddError err = EDD_NOERR;
    char cmd[32];
    int key;
    for (size_t i = 0; i < E; i++) {
        fscanf(input_file, "%s", cmd);

        if (!strcmp(cmd, "LOG")) {
            bst_print(&err, bst, output_file);
        }

        if (!strcmp(cmd, "DICTSORT")) {
            size_t word_count = 0;
            size_t word_length = 0;
            fscanf(input_file, " %zu %zu", &word_count, &word_length);

            char **words = calloc(word_count, sizeof(char *));
            for (size_t i = 0; i < word_count; i++) {
                words[i] = calloc(word_length + 1, sizeof(char));
                fscanf(input_file, "%s", words[i]);
            }

            dictsort(words, word_count, word_length, output_file);

            for (size_t i = 0; i < word_count; i++) {
                free(words[i]);
            }

            free(words);
        }

        if (!strcmp(cmd, "INSERT")) {
            fscanf(input_file, " %d", &key);
            bst_insert(bst, key, output_file);
        }

        if (!strcmp(cmd, "SEARCH")) {
            fscanf(input_file, " %d", &key);
            bst_search(bst, key, output_file);
        }

        if (!strcmp(cmd, "DELETE")) {
            fscanf(input_file, " %d", &key);
            bst_delete(bst, key, output_file);
        }

        if (!strcmp(cmd, "TWOSUM")) {
            size_t size = 0;
            int sum = 0;
            fscanf(input_file, " %zu %d", &size, &sum);

            Bst *new_bst = bst_create(NULL);
            for (size_t i = 0; i < size; i++) {
                fscanf(input_file, "%d", &key);
                bst_insert(new_bst, key, NULL);
            }

            bst_two_sum(new_bst, sum, output_file);

            bst_destroy(&err, new_bst);
        }
    }

    /* Liberamos memoria y cerramos archivos de input y output */
    bst_destroy(&err, bst);
    fclose(input_file);
    fclose(output_file);

    return 0;
}
