#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#define NB_MOT 10

typedef struct Query{

    char mot[MAX_MOT];
    struct Query *next;

}Query;

typedef struct Score{

    int id;
    int score;
}

void Recherche(Correspondance *c, Cascade_hte *index);
Query* decoupage(char recherche_brute[]);
void classement(Correspondance *c, Query *q);

#endif // USER_H_INCLUDED
