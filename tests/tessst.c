#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE * myFile = fopen( "anExistingFile", "r" );
    int rc = fputc( '!', myFile );

    printf( "Results == %d %d %d\n", rc, ferror( myFile ), errno );
    perror( "My message" );

    rc = fclose( myFile );
        
    return 0;
}
