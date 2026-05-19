#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *margeAlternately ( const char * a , const char * b ) {

    char * res = (char*) malloc (strlen(a) + strlen(b) + 1) ;
    char *p = res ; 

    while (*a || *b) {
        if (*a) *p++ = *a++ ;
        if (*b) *p++ = *b++ ;
    }
    *p = '\0' ;

    return  res ;

}

int main ()
{
    
    char word [2][100] ;
    for (int i = 0 ; i < 2 ; i ++) {
        printf ("Please Input Word%d : " , i ) ; 
        scanf ("%99s" , word[i] ) ;
    }

    char *result = margeAlternately (word[0] , word[1]) ;
    if (result) {
        printf ("The New Word : %s " , result ) ;
        free (result) ;
    }

    return 0 ;
    
}














