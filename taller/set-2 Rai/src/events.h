#ifndef EDDSET_EVENTS_H
#define EDDSET_EVENTS_H

#include <stdio.h>

#include "libedd/libedd_err.h"
#include "libedd/libedd_bst.h"

/* Declaración de funciones */

void dictsort(char **words, size_t word_count, size_t word_length, FILE *output_file);
BstNode *bst_search(Bst *bst, int key, FILE *output_file);
void bst_insert(Bst *bst, int key, FILE *output_file);
void bst_delete(Bst *bst, int key, FILE *output_file);
void bst_two_sum(Bst *bst, int sum, FILE *output_file);

#endif
