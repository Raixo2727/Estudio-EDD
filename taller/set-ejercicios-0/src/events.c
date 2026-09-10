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
    SllNode* nodo_actual = sll -> head;
    SllNode* nodo_anterior = NULL;

    while (nodo_actual != NULL && nodo_actual -> data != k ) {
        nodo_anterior = nodo_actual;
        nodo_actual = nodo_actual -> next;
    }

    if (nodo_actual == NULL) {
        fprintf(output_file, "No se ha encontrado el numero %d en la lista ligada.\n", k);
    } else if(nodo_anterior == NULL) {
        sll -> head = nodo_actual -> next;
        free(nodo_actual);
        fprintf(output_file, "Se ha eliminado el numero %d en la lista ligada.\n", k);
    } else {
        nodo_anterior -> next = nodo_actual -> next;
        free(nodo_actual);
        fprintf(output_file, "Se ha eliminado el numero %d en la lista ligada.\n", k);
    }
}

void sll_reverse(Sll *sll, FILE *output_file) {
    SllNode* nodo_anterior = NULL;
    SllNode* nodo_actual = sll -> head;
    SllNode* nodo_posterior = NULL;

    sll -> tail = nodo_actual;
    while (nodo_actual != NULL) {
        nodo_posterior = nodo_actual -> next;
        nodo_actual -> next = nodo_anterior;

        nodo_anterior = nodo_actual;
        nodo_actual = nodo_posterior;
    }
    sll -> head = nodo_anterior;

    fprintf(output_file, "Se ha invertido la lista ligada:\n");
    SllNode* curr = sll ->head;
    while (curr != NULL) {
        fprintf(output_file, "%d\n", curr->data);
        curr = curr -> next;
    }
}

void sll_shift(Sll *sll, int k, FILE *output_file) {
    if (sll == NULL || sll->head == NULL) {
        return;
    }

    // Calculamos el tamaño real manualmente
    int sll_size = 0;
    SllNode* count_node = sll->head;
    while (count_node != NULL) {
        sll_size++;
        count_node = count_node->next;
    }

    int k_efectivo = k % sll_size;

    if (sll_size > 1 && k_efectivo > 0) {
        SllNode* curr = sll->head;
        for (int i = 0; i < (sll_size - k_efectivo - 1); i++) {
            curr = curr->next;
        }

        SllNode* nueva_cabeza = curr->next;
        curr->next = NULL;

        SllNode* tail_antigua = nueva_cabeza;
        while (tail_antigua->next != NULL) {
            tail_antigua = tail_antigua->next;
        }

        tail_antigua->next = sll->head;
        sll->head = nueva_cabeza;
        sll->tail = curr;
    }

    fprintf(output_file, "Se ha hecho el shift de %d posiciones en la lista ligada:\n", k);
    SllNode* iter = sll->head;
    while (iter != NULL) {
        fprintf(output_file, "%d\n", iter->data);
        iter = iter->next;
    }
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
