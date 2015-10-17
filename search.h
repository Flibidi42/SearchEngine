#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include "user.h"

void maj_classement(double *classement, Cascade_brche *result, int taille, Correspondance *docs); // Mets à jour le classement si on trouve une correspondance
void classement(Correspondance *c, Query *q, Cascade_hte *i); // Etablit le classement

#endif // SEARCH_H_INCLUDED
