#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED
#include "struct.h"
#define TAILLE_MAX_DOC 100

Correspondance* etablir_liste_doc();
Cascade_hte* indexation(Correspondance* table_co);

#endif // INDEX_H_INCLUDED
