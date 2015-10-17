#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "user.h"
#include "struct.h"
#include "search.h"

void classement(Correspondance *c, Query *q, Cascade_hte *i){
    Query *rech = q;
    Correspondance *docs = c;
    Cascade_hte *index = i;
    double *classement;
    int taille = 0;

    while(docs != NULL){ // calcul du nombre de docs
        taille ++;
        docs = docs->next;
    }

    classement = malloc(sizeof(double) * taille); // On crée la table des resultats

    while(rech != NULL){
        index = i;
        while(index != NULL){
            if(!strcmp(rech->mot, index->mot))
               maj_classement(classement, index->branche, taille, c);
            index = index->next;
        }
        rech = rech->next;
    }
}

double IDF(int taille, Cascade_brche *result){ // Calcul de l'IDF
    double total = (double) taille;
    double match = 0.;
    Cascade_brche *r = result;
    while(r!= NULL){
        match += 1.;
        r = r->next;
    }
    return (log((total +1)/match)); // Formule de l'IDF
}



void maj_classement(double *classement, Cascade_brche *result, int taille, Correspondance *docs){
    double IDF = IDF(taille, result);
    int i;
    Cascade_brche *parcours = result;
    while(parcours != NULL){


        parcours = parcours->next;
    }

}
