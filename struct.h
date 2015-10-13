#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#define MAX_MOT 30

typedef struct Cascade_brche // Partie haute de la liste de liste chainée
{
    int doc;
    int nombre;
    struct Cascade_brche *next;
} Cascade_brche;

typedef struct Cascade_hte // Partie descendante de la liste chainée
{
    char mot[30];
    Cascade_brche *branche;
    struct Cascade_hte *next;
} Cascade_hte;

typedef struct Correspondance // Table de lien num_document <-> Nom document
{
    int id;
    char nom[100];
    unsigned int taille;
    struct Correspondance *next;
} Correspondance;

void ajouter_doc(Cascade_brche *c, int doc);
void ajout_mot(Cascade_hte **cascade, char *mot, int doc);
void afficher_index(Cascade_hte *c);
void ajout_correspondance(Correspondance **c, int id, char *nom);

#endif // STRUCT_H_INCLUDED
