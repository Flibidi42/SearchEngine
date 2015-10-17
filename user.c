#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"
#include "struct.h"
#include "search.h"

void Recherche(Correspondance *c, Cascade_hte *index)
{
    // variables
    char recherche_brute[(NB_MOT*MAX_MOT + NB_MOT - 1)];
    char *ca = NULL, char_vidage;

    //execution
    if (fgets(recherche_brute, NB_MOT*MAX_MOT + NB_MOT - 1, stdin) != NULL)
    {
        ca = strchr(recherche_brute, '\n');
        if (ca != NULL)
            *ca = '\0';
        while((char_vidage=getchar())!= '\n' && char_vidage!=EOF); // vidage buffer
        Query* recherche_decoupe = decoupage(recherche_brute);
        // A completer
    }
    else
    {
        printf("Erreur saisie\n");
        return;
    }
}

Query* decoupage(char recherche_brute[]){
    int i, j =0;
    Query *rech_dec = malloc(sizeof(Query));
    Query *q = rech_dec;

    for(i = 0; i<strlen(recherche_brute); i++){
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

