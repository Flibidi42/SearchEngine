#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include "user.h"

#define K 5 // constante transfo TF
#define B 0.5 // constante Normalizer

void maj_classement(double *classement, Cascade_brche *result, int taille, Correspondance *docs, double moyenne_t); // Mets à jour le classement si on trouve une correspondance
void classement(Correspondance *c, Query *q, Cascade_hte *i); // Etablit le classement
double IDF(int taille, Cascade_brche *result);

#endif // SEARCH_H_INCLUDED
