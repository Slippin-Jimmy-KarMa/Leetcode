#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_gcd ( int a , int b ){
    while ( b != 0 ) {
        int Temp = a % b ;
        a = b ; 
        b = Temp ;
    }
    return a ;
}

char * gcdOfStrings ( char *str1 , char *str2 ) {

    int len1 = strlen ( str1 ) ;
    int len2 = strlen ( str2 ) ;

    char *t1 = (char*) malloc ( len1 + len2 + 1 ) ;
    char *t2 = (char*) malloc ( len1 + len2 + 1 ) ; 

    sprintf ( t1 , "%s%s" , str1 , str2 ) ;
    sprintf ( t2 , "%s%s" , str2 , str1 ) ;

    if ( strcmp ( t1 , t2 ) != 0 ) {
        free(t1) ;
        free(t2) ;
        return "" ;
    }
    free(t1) ;
    free(t2) ;

    int gcd_len = get_gcd( len1 , len2 ) ;
    char *result = (char*) malloc ( gcd_len + 1 ) ;
    strncpy ( result , str1 , gcd_len ) ;
    result [gcd_len] = '\0' ;

    return result ;

}



int main ()
{
    char str1[] = "ABABABAB" ;
    char str2[] = "ABAB" ;

    char *result = gcdOfStrings ( str1 , str2 ) ;

    printf( "The Result = %s " , result ) ;
    free(result) ;

    return 0 ;
}