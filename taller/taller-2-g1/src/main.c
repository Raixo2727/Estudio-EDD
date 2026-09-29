#include "events.h"
#include "libedd/blob.h"
#include <stdio.h>
#include <stdlib.h>

// Puedes setear la siguiente variable a 'true'
// para activar los mensajes de debugging de LibEDD.
bool EDD_DEBUG = false;

// **************************************
// ******** FUNCIONES AUXILIARES ********
// **************************************

static bool check_arguments(int argc, char **argv) {
    if (argc != 3) {
        printf("Uso: %s INPUT_PATH OUTPUT_PATH\n", argv[0]);
        printf("Donde:\n");
        printf("  INPUT_PATH es el path al archivo de input\n");
        printf("  OUTPUT_PATH es el path al archivo de output\n");
        exit(1);
    }

    return true;
}

int *get_bits(FILE *input_file, size_t *length) {
    char word[*length + 1];
    fscanf(input_file, "%s", word);

    int *bits = malloc(*length * sizeof(int));

    for (size_t i = 0; i < *length; i++) {
        bits[i] = word[i] - '0';
    }

    return bits;
}

// **************************************
// ********** MANEJO DE EVENTOS *********
// **************************************

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

    EddError err = EDD_NOERR;

    Bst *bst = bst_create(NULL);

    char cmd[32];
    for (size_t i = 0; i < E; i++) {
        fscanf(input_file, "%s", cmd);

        // **************************************
        // ******** EVENTOS PREDEFINIDOS ********
        // **************************************

        if (!strcmp(cmd, "PRINT")) {
            bst_print(&err, bst, output_file);
        }

        if (!strcmp(cmd, "INSERT-WORD")) {
            size_t length;
            fscanf(input_file, "%zu", &length);

            int *bits = get_bits(input_file, &length);

            bst_insert_word(bst, length, bits);
            fprintf(output_file, "Se inserto el numero binario ");
            for (size_t i = 0; i < length; i++) {
                fprintf(output_file, "%d", bits[i]);
            }
            fprintf(output_file, "\n");

            free(bits);
        }

        // **************************************
        // ********** EVENTOS TALLER 2 **********
        // **************************************

        if (!strcmp(cmd, "SEARCH-WORD")) {
            size_t length;
            fscanf(input_file, "%zu", &length);

            int *bits = get_bits(input_file, &length);

            // bool found = bst_search_word(bst, length, bits);
            bool found = bst_search_word(bst->root, length, bits, 0);
            if (found) {
                fprintf(output_file, "S");
            } else {
                fprintf(output_file, "No s");
            }

            fprintf(output_file, "e encontro el numero binario ");
            for (size_t i = 0; i < length; i++) {
                fprintf(output_file, "%d", bits[i]);
            }
            fprintf(output_file, " en el ABB\n");

            free(bits);
        }

        if (!strcmp(cmd, "WITH-PREFIX")) {
            size_t length;
            fscanf(input_file, "%zu", &length);

            int *bits = get_bits(input_file, &length);

            int count = bst_with_prefix(bst, length, bits);
            fprintf(output_file, "Cantidad de numeros binarios con prefijo ");
            for (size_t i = 0; i < length; i++) {
                fprintf(output_file, "%d", bits[i]);
            }
            fprintf(output_file, ": %d\n", count);

            free(bits);
        }
    }

    /* Liberamos memoria y cerramos archivos */

    bst_destroy(&err, bst);

    fclose(output_file);
    fclose(input_file);

    return 0;
}
