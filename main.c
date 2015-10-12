#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "search.h"
#include "index.h"

int main()
{
    /*Code de test*/
    Correspondance *c = etablir_liste_doc();
    Cascade_hte *index = indexation(c);
    //afficher_index(index);
    Recherche(c, index);
    return 0;
}
