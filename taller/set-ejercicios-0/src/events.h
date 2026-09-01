#ifndef SET0_EVENTS_H
#define SET0_EVENTS_H

#include "../libedd/libedd_sll.h"

/* Declaración de funciones */

void sll_enter(Sll *sll, int k, FILE *output_file);
void sll_delete(Sll *sll, int k, FILE *output_file);
void sll_reverse(Sll *sll, FILE *output_file);
void sll_shift(Sll *sll, int k, FILE *output_file);
void sll_split(Sll *sll, FILE *output_file);

#endif
