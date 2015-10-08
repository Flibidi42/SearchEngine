#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#define N 5
typedef struct Resultats
{
    char Doc_name [200];
    struct resultats *next;
} Resultats;

typedef struct Cascade_brche
{
    int doc;
    int nombre;
    struct Cascade_brche *next;
}Cascade_brche;

typedef struct Cascade_hte
{
    char mot[30];
    Cascade_brche *branche;
    struct Cascade_hte *next;
} Cascade_hte;

typedef struct correspondance
{
    int id;
    char nom[300];
    struct correspondance *next;
} correspondance;

void ajouter_doc(Cascade_brche *c, int doc);
void ajout_mot(Cascade_hte **cascade, char *mot, int doc);

#endif // STRUCT_H_INCLUDED
