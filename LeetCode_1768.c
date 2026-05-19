#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* margeAlternately ( const char * word1 , const char * word2 ) {
    
    int n1 = strlen (word1) ;
    int n2 = strlen (word2) ;

    int maxVal = n1 > n2 ? n1 : n2 ;

    char *word = (char*)calloc(( n1 + n2 +1 ) , sizeof(char) ) ;

    if (word == NULL) return NULL;

    int k = 0 ;
    for ( int i = 0 ; i < maxVal ; i ++ ){
        if ( i < n1 ) word[k++] = word1[i] ;
        if ( i < n2 ) word[k++] = word2[i] ;
    }
    word[k] = '\0' ;

    return word ;
}

int main()
{
    char word1 [100] ;
    char word2 [100] ;

    printf ("Please Input Word1 :") ;
    scanf ("%99s" , word1 ) ;
    printf ("Please Input Word2 :") ;
    scanf ("%99s" , word2 ) ;

    char *result = margeAlternately ( word1 , word2 ) ;
    printf ("The Word : %s " , result ) ;

    free (result) ;
    result = NULL ;

    return 0 ;
}