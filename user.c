#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "struct.h"

void Recherche(Correspondance *c, Cascade_hte *index)
{
    // variables
    char recherche_brute[(NB_MOT*MAX_MOT + NB_MOT - 1)];
    char *c = NULL;


    //execution
    if (fgets(recherche_brute, NB_MOT*MAX_MOT + NB_MOT - 1, stdin) != NULL)
    {
        c = strchr(chaine, '\n');
        if (c != NULL)
            *c = '\0';
        while((*c=getchar())!= '\n' && *c!=EOF); // vidage buffer
        Query* recherche_decoupe = decoupage(recherche_brute);

    }
    else
    {
        printf("Erreur saisie\n");
        return;
    }
}

Query* decoupage(char recherche_brute[]){
    int i, j =-1;
    int new_mot = 1;
    Query *rech_dec = malloc(sizeof(Query));
    Query *q = rech_dec;

    for(i = 0, i<strlen(recherche_brute), i++){
        if(recherche_brute[i]>=48 && recherche_brute[i]<=122 && (recherche_brute[i]>= 65 || recherche_brute[i]<= 57) && (recherche_brute[i]>= 97 || recherche_brute[i]<= 90) && j < MAX_MOT-1){
            if(j == 0 && i != 0){
                q->next = malloc(sizeof(Query));
                q = q->next;
                q->next = NULL;
            }
            q->mot[j] = recherche_brute[i];
            j++;
        }
        else if(recherche_brute[i] == ' '){
            q->mot[j] = '\0';
            j = 0;
        }
    }
    return rech_dec;
}

void classement(Correspondance *c, Query *q){
    Query *rech = q;
    Correspondance *docs = c;
    Score *classement;
    int taille = 0;

    while(docs != NULL){ // calcul du nombre de docs
        taille ++;
        docs = docs->next
    }

    classement = malloc(sizeof(Score) * taille); // On crée le tableau des resultats


}
