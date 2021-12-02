#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    // La chaine de caractères à traiter.
    char str[] = "- Voici une phrase avec quelques séparateurs ! -";
    // La définitions de séparateurs connus.
    const char * separators = " ,.-!";

    // On cherche à récupérer, un à un, tous les mots (token) de la phrase
    // et on commence par le premier.
    char * strToken = strtok ( str, separators );
    while ( strToken != NULL ) {
        printf ( "%s\n", strToken );
        // On demande le token suivant.
        strToken = strtok ( NULL, separators );
    }

    return EXIT_SUCCESS;
}
