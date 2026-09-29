#ifndef WORKSHOP_EVENTS_H
#define WORKSHOP_EVENTS_H

#include <stdio.h>

#include "libedd/libedd_bst.h"

/* Declaración de funciones */
bool bst_search_word(BstNode *node, size_t length, int *word, size_t idx);
int bst_with_prefix(Bst *bst, size_t prefix_size, int *prefix);

#endif
