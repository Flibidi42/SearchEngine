#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "user.h"
#include "struct.h"
#include "search.h"

int* classement(Correspondance *c, Query *q, Cascade_hte *i){
    Query *rech = q;
    Correspondance *docs = c;
    Cascade_hte *index = i;
    double *classement;
    int taille = 0, i, j;
    double moyenne_t = 0;

    while(docs != NULL){ // calcul du nombre de docs
        taille ++;
        moyenne_t += docs->taille;
        docs = docs->next;
    }

    moyenne_t /= ((double) taille);

    classement = malloc(sizeof(double) * taille); // On crée la table des resultats

    while(rech != NULL){
        index = i;
        while(index != NULL){
            if(!strcmp(rech->mot, index->mot)){
               maj_classement(classement, index->branche, taille, c, moyenne_t);
               break;
            }
            index = index->next;
        }
        rech = rech->next;
    }


    int *classement_final = malloc(sizeof(int) * taille); // on etablit la liste des indices généraux classés
    int i = 0, j = 0, decalage = 0, valeur_decal = 0, tempo;
    for(i = 0; i<taille; i++){
        for(j = 0; j<taille; j++){
            if(decalage){
                tempo = classement_final[j];
                classement_final[j] = valeur_decal;
                valeur_decal = tempo;
            }
            else{
                if(classement[classement_final[j]]>classement[i])
                    continue;
                else
                    valeur_decal = classement_final[j];
                    classement_final[j] = i;
                    decalage = 1;
            }
        }
        decalage = 0;
    }
    return classement_final;
}

double IDF(int taille, Cascade_brche *result){ // Calcul de l'IDF (penalisation mots communs)
    double total = (double) taille;
    double match = 0.;
    Cascade_brche *r = result;
    while(r!= NULL){
        match += 1.;
        r = r->next;
    }
    return (log((total +1)/match)); // Formule de l'IDF
}



void maj_classement(double *classement, Cascade_brche *result, int taille, Correspondance *docs, double moyenne_t){
    double idf = IDF(taille, result);
    double TF = 1.0;
    double Norm = 0;
    int id, stop;
    Cascade_brche *parcours = result;
    Correspondance *p_docs = docs;
    while(parcours != NULL){
        id = parcours->doc;
        stop = p_docs->id;
        if(stop != id){ // objectif : chercher le doc dans la table des correspondance
            if(p_docs->next == NULL){
                printf("Erreur : index des documents corrompu\n");
                return;
            }
            p_docs = p_docs->next;
            while(id != p_docs->id && p_docs->id != stop){
                if(p_docs == NULL)
                    p_docs = docs;
            }
            if(p_docs->id != id){
                printf("Erreur : index des documents corrompu\n");
                return;
            }
        }
        Norm = 1-B+B*((p_docs->taille)/moyenne_t);
        TF = (K+1)*(parcours->nombre)/(K*Norm + (parcours->nombre));
        classement[parcours->doc - 1] += TF*idf;
        parcours = parcours->next;
    }

}
