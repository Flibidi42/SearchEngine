#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#define NB_MOT 10
#include "index.h"

typedef struct Query{

    char mot[MAX_MOT];
    struct Query *next;

}Query;

void Recherche(Correspondance *c, Cascade_hte *i); // Fonction de recherche principale
Query* decoupage(char recherche_brute[]); // Découpage de la recherche en "bag of words"



#endif // USER_H_INCLUDED
