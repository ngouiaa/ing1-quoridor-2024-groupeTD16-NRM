#include <stdio.h>
#include <stdlib.h>
#include "tableauex.h"


int main(void) {
    int p1[T][T];
    initialiser_plateau(p1,2);
    afficher_plateau(p1);
    return 0;

}
