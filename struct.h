#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct Cascade_brche // Partie haute de la liste de liste chainée
{
    int doc;
    int nombre;
    struct Cascade_brche *next;
}Cascade_brche;

typedef struct Cascade_hte // Partie descendante de la liste chainée
{
    char mot[30];
    Cascade_brche *branche;
    struct Cascade_hte *next;
} Cascade_hte;

typedef struct correspondance // Table de lien num_document <-> Nom document
{
    int id;
    char nom[300];
    struct correspondance *next;
} correspondance;

void ajouter_doc(Cascade_brche *c, int doc);
void ajout_mot(Cascade_hte **cascade, char *mot, int doc);

#endif // STRUCT_H_INCLUDED
