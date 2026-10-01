#ifndef EDDSET_EVENTS_H
#define EDDSET_EVENTS_H

#include <stdio.h>

#include "bst.h"

/* Declaración de funciones */
void balance(Bst* tree, FILE* output_file);
void rbt_two_four_equiv(Bst *rbt, FILE *output_file);

#endif
