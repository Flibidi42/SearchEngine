#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "index.h"
#include "struct.h"

Correspondance* etablir_liste_doc()
{
    Correspondance* table = NULL;
    int i = 1;
    FILE *fichier_doc = fopen("liste_doc.lst", "r");
    char doc[TAILLE_MAX_DOC];
    if(fichier_doc == NULL)
    {
        printf("Fichier d'indexation des docs introuvable");
        return NULL;
    }
    while(fgets(doc, TAILLE_MAX_DOC, fichier_doc) > 0)
    {
        if(doc[strlen(doc)-1] == '\n')
            doc[strlen(doc)-1] = '\0';
        ajout_correspondance(&table, i, doc);
        i++;
    }
    fclose(fichier_doc);
    return table;
}

void affichage_correspondance(Correspondance* table)  // Uniquement du debug
{
    Correspondance *c = table;
    while(c != NULL)
    {
        printf("Doc %d -> %s\n", c->id, c->nom);
        c = c->next;
    }
}

Cascade_hte* indexation(Correspondance* table_co)
{
    // Variables
    Cascade_hte* index = NULL;
    Correspondance* alias_doc = table_co;
    char c, mot[MAX_MOT];
    int mot_envoye = 1, i =0;
    FILE *fichier;

    //Execution
    while(alias_doc != NULL)  // parcours de doc de la table
    {
        fichier = fopen(alias_doc->nom, "r");
        if(fichier == NULL)
        {
            printf("Erreur : fichier %s introuvable", alias_doc->nom);
            return NULL;
        }
        while((c = fgetc(fichier)) != EOF)  // parcours des caractères
        {
            if(c>=48 && c<=122 && (c>= 65 || c<= 57) && (c>= 97 || c<= 90) && i < MAX_MOT)
            {
                mot_envoye = 0;
                mot[i] = c;
                i++;
            }
            else if(!mot_envoye)
            {
                mot_envoye ++;
                mot[i] = '\0';
                ajout_mot(&index, mot, alias_doc->id);
                i = 0;
            }
        }
        if(!mot_envoye)
        {
            mot[i] = '\0';
            ajout_mot(&index, mot, alias_doc->id);
        }
        alias_doc = alias_doc->next; // On passe au doc suivant
        fclose(fichier);
    }
    return index;
}
