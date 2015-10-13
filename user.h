#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#define NB_MOT 10
#include "index.h"

typedef struct Query{

    char mot[MAX_MOT];
    struct Query *next;

}Query;

typedef struct Score{

    int id;
    int score;
}Score;

void Recherche(Correspondance *c, Cascade_hte *i);
Query* decoupage(char recherche_brute[]);
void classement(Correspondance *c, Query *q, Cascade_hte *index);
void maj_classement(Score *classement, Cascade_brche *result);

#endif // USER_H_INCLUDED
