#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#define NB_MOT 10
#include "index.h"
#define REQ_MAX (NB_MOT*MAX_MOT + NB_MOT - 1)

typedef struct Query{

    char mot[MAX_MOT];
    struct Query *next;

}Query;

void Recherche(Correspondance *c, Cascade_hte *i); // Fonction de recherche principale
Query* decoupage(char recherche_brute[]); // Découpage de la recherche en "bag of words"
void Affichage_resultats(double* classement, int taille);


#endif // USER_H_INCLUDED
