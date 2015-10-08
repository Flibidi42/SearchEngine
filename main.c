#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "search.h"
#include "struct.h"


int main()
{
    char query[1000];
    char c;
    Cascade_hte *res = NULL;
    res = malloc(sizeof(Cascade_hte));
    strcpy(res->mot, "Teste");
    res->branche = malloc(sizeof(Cascade_brche));
    res->branche->doc = 1;
    res->branche->nombre = 5;
    res->branche->next = NULL;/*
    res->branche->next = malloc(sizeof(Cascade_hte));
    res->branche->next->doc = 2;
    res->branche->next->nombre = 6;
    res->branche->next->next = NULL;
    res->next = malloc(sizeof(Cascade_hte));
    strcpy(res->next->mot, "Test2");
    res->next->branche = malloc(sizeof(Cascade_brche));
    res->next->branche->doc = 3;
    res->next->branche->nombre = 4;
    res->next->branche->next = malloc(sizeof(Cascade_hte));
    res->next->branche->next->doc = 4;
    res->next->branche->next->nombre = 2;
    res->next->branche->next->next = NULL;
    res->next->next = NULL;*/
    ajout_mot(&res, "Teste", 1);
    ajout_mot(&res, "Teste", 2);
    afficher(res);
    /*printf("*** SearchEngine program ***\n\n\n");
    printf("Your query : ");
    scanf("%1000s", query);
    while((c=getchar()) != '\n' || c != EOF);
    traiter_requete(query, res);
    //afficher_res(res);*/
    return 0;
}
