#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Struct.h"

void ajout_mot(Cascade_hte **cascade, char *mot, int doc){
    if(*cascade == NULL){ // cas d'une cascade vide de base
        *cascade = malloc(sizeof(Cascade_hte));
        strcpy((*cascade)->mot,mot);
        (*cascade)->next = NULL;
        (*cascade)->branche = malloc(sizeof(Cascade_brche));
        (*cascade)->branche->doc = doc;
        (*cascade)->branche->nombre = 1;
        (*cascade)->branche->next = NULL;
        return;
    }
    int trouve = 0;
    Cascade_hte *c1 = *cascade;
    Cascade_hte *tempo = c1;
    Cascade_brche *c2 = NULL;
    while(c1 != NULL){ // parcours mots
        if(!strcmp(c1->mot, mot)){
            c2 = c1->branche;
            while(c2 != NULL){ // parcours des docs
                if(c2->doc == doc){
                    c2->nombre ++;
                    return;
                }
                c2 = c2->next;
            }
            ajouter_doc(c1->branche, doc); // On ajoute le doc manquant
            return;
        }
        tempo = c1; // tempo contient le maillon
        c1 = c1->next;
    }
    tempo->next = malloc(sizeof(Cascade_hte)); // création du mot
    strcpy(tempo->next->mot,mot);
    tempo->next->next = NULL;
    tempo->next->branche = malloc(sizeof(Cascade_brche));
    tempo->next->branche->doc = doc;
    tempo->next->branche->nombre = 1;
    tempo->next->next = NULL;

}

void ajouter_doc(Cascade_brche *c, int doc){ // c n'est pas NULL car forcément un doc si l'entrée de mot a été créée
    while(c->next != NULL)
        c = c->next;
    c->next = malloc(sizeof(Cascade_brche));
    c->next->next = NULL;
    c->next->nombre = 1;
    c->next->doc = doc;
}

void afficher(Cascade_hte *c){
    Cascade_hte *c1 = c;
    if(c1 == NULL)
        return;
    Cascade_brche *c2;
    while(c1 != NULL){
        c2 = c1->branche;
        printf("Mot %s : - ", c1->mot);
        while(c2 != NULL){
            printf("Doc : %d -> %d fois - ", c2->doc, c2->nombre);
            c2 = c2->next;
        }
        c1 = c1->next;
        printf("\n");
    }
}
