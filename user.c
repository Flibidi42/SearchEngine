#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"
#include "struct.h"
#include "search.h"

void Recherche(Correspondance *c, Cascade_hte *index)
{
    // variables
    char recherche_brute[REQ_MAX];
    char *ca = NULL, char_vidage;
    int taille = 0;
    Correspondance *docs = c;

    while(docs != NULL){ // calcul du nombre de docs
        taille ++;
        docs = docs->next;
    }

    //execution
    if (fgets(recherche_brute, REQ_MAX-1, stdin) != NULL)
    {

        ca = strchr(recherche_brute, '\n');
        if (ca != NULL)
            *ca = '\0';
        else{
            while((char_vidage=getchar())!= '\n' && char_vidage!=EOF); // vidage buffer
            recherche_brute[REQ_MAX-1] = '\0';
        }
        Query* recherche_decoupe = decoupage(recherche_brute);
        int *tableau_resultats = NULL;
        tableau_resultats = classement(c, recherche_decoupe, index, &taille);
        Affichage_resultats(tableau_resultats, taille, c);
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
        else if(recherche_brute[i] == ' ' || recherche_brute[i] == '\0'){
            q->mot[j] = '\0';
            j = 0;
        }
    }
    q->mot[j] = '\0';
    return rech_dec;
}


void Affichage_resultats(int* classement, int taille, Correspondance *c){

    Correspondance *docs = c;
    int i = 0;
    for(i = 0; i < taille; i++){
        while(docs != NULL && docs->id != i)
            docs = docs->next;
        if(docs == NULL){
            printf("Erreur");
            return;
        }
        printf("Doc %d : %s\n", classement[i], docs->nom);
        docs = c;
    }
}
