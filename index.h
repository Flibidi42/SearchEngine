#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED
#include "struct.h"
#define TAILLE_MAX_DOC 100

Correspondance* etablir_liste_doc(); // Etablit la liste des documents
Cascade_hte* indexation(Correspondance* table_co); // Etablit index
void afficher_index(Cascade_hte *c); // Affiche index (debug)

#endif // INDEX_H_INCLUDED
