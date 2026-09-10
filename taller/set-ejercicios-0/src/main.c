#include "events.h"

/*
 * Puedes setear la siguiente variable a 'true'
 * para activar los mensajes de debugging de LibEDD.
 */
bool EDD_DEBUG = false;

/* sll_log:
 * Función para imprimir elementos de una SLL.
 * Usada sólo para verificar el output de algunos tests.
 * Quizá analizar este código te ayude para resolver los ejercicios ;)
 */
void sll_log(Sll *sll, FILE *output_file) {
    fprintf(output_file, "Estado de la lista ligada:\n");

    SllNode *curr = sll->head;
    while (curr != NULL) {
        fprintf(output_file, "%d\n", curr->data);
        curr = curr->next;
    }
}

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

int main(int argc, char **argv) {
    //Primero Revisamos que se esten pasando correctamente los archivos de input y output
    //Luego abrimos los archivos
    check_arguments(argc, argv);
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");


    //la función fscanf lee desde una linea de un archivo de input, la cadena que aparece en el segundo argumento
    //expresa lo que la función va a leer del archivo. Por ejemplo: %zu lee un int que será guardado en una variable de tipo size_t
    //el tercer argumento recibe una dirreción de memoria donde se guardará lo que se leyó del input
    size_t E;
    int buffer = fscanf(input_file, "%zu", &E);
    if (buffer != 1) {
        printf("Error reading number of test events");
        return 1;
    }

    EddError err = EDD_NOERR;

    //creamos una lista ligada vacia
    Sll *sll = sll_create();
    int k = 0;

    char cmd[32];
    for (size_t i = 0; i < E; i++) {

        //aca tenemos el for principal de eventos, leemos un %s (string) del archivo de input y luego comparamos a que evento se referia, si el evento
        //despues del string tiene mas atributos que leer, los leemos con fscanf y sino solo llamamos a la función que resuelve ese evento.
        fscanf(input_file, "%s", cmd);

        if (!strcmp(cmd, "LOG")) {
            sll_log(sll, output_file);
        }

        if (!strcmp(cmd, "ENTER")) {
            fscanf(input_file, " %d", &k);
            sll_enter(sll, k, output_file);
        }

        if (!strcmp(cmd, "DELETE")) {
            fscanf(input_file, " %d", &k);
            sll_delete(sll, k, output_file);
        }

        if (!strcmp(cmd, "REVERSE")) {
            sll_reverse(sll, output_file);
        }

        if (!strcmp(cmd, "SHIFT")) {
            fscanf(input_file, " %d", &k);
            sll_shift(sll, k, output_file);
        }

        if (!strcmp(cmd, "SPLIT")) {
            sll_split(sll, output_file);
        }
    }

    /* Liberamos la memoria asignada dinámicamente para la SLL */
    sll_destroy(&err, sll);

    /* Cerramos archivos de input y output */
    fclose(input_file);
    fclose(output_file);

    return 0;
}
