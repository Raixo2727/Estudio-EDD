#include "events.h"
#include <stdio.h>
#include <stdlib.h>
#include "../libedd/libedd_sll.h"

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
 * Un pequeño tip: puedes usar la función fprintf de stdio.h para
 * imprimir un string con formato a un archivo, de forma análoga
 * a como printf imprime a stdout.
 *
 * Otro aspecto que les puede ayudar: para las funciones donde
 * el primer argumento es "EddError *err", como por ejemplo
 * sll_node_destroy, deben crear una variable (idealmente al
 * comienzo de la función en la que estén trabajando) del siguiente
 * modo:
 *
 * EddError err = EDD_NOERR;
 *
 * Y luego, cuando hagan una llamada a una función que lo requiera,
 * deben hacerlo pasando la dirección de memoria de esta variable err,
 * es decir, &err. Por ejemplo:
 *
 * sll_node_destroy(&err, node);
 *
 * Los detalles de por qué esto es necesario estarán en la guía
 * de talleres sobre LibEDD, pero de modo resumido, es para ayudarlos
 * con el debugging en los talleres ;)
 *
 * Mucho éxito!
 */

void sll_enter(Sll *sll, int k, FILE *output_file) {
    SllNode *node = calloc(1, sizeof(SllNode));
    node -> data = k;

    if (sll -> tail != NULL) {
        sll -> tail -> next = node;
    } else if (sll -> head == NULL) {
        sll -> head = node;
    }
    
    sll -> tail = node;
    fprintf(output_file, "Se ha insertado el numero %d en la lista ligada.\n", k);
}

void sll_delete(Sll *sll, int k, FILE *output_file) {
    // TODO
}

void sll_reverse(Sll *sll, FILE *output_file) {
    // TODO
}

void sll_shift(Sll *sll, int k, FILE *output_file) {
    // TODO
}

void sll_split(Sll *sll, FILE *output_file) {
    // TODO
    // En esta función, puedes cambiar la definición para retornar
    // la otra mitad de la lista en un struct Sll. De otro modo,
    // deberías liberar la memoria de los nodos de la otra lista
    // una vez impresos en el archivo de salida para no generar leaks.
    // En los tests que entregamos, no se hace uso de la otra lista,
    // con lo que no es problema.
}
