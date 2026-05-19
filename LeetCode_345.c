#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int isVowel ( char s ) {
    switch ( s ) {
        case 'a' : case 'A' : case 'e' : case 'E' :
        case 'i' : case 'I' : case 'o' : case 'O' :
        case 'u' : case 'U' :
            return true ;
        default : 
            return false ;
    }
}

char *reverseVowels ( char *s ) {
    
    char right = 0 ;
    char left = strlen( s ) - 1 ;

    while ( left > right ) {
        
        while ( left > right && !isVowel(s[left]) ) {
            left -- ;
        }
        while ( left > right && !isVowel(s[right]) ) {
            right ++ ;
        }
        if ( left > right ) {
            char Tamp = s[right] ;
            s[right] = s[left] ;
            s[left] = Tamp ;
            right ++ ;
            left -- ;
        }
    }

    return s ;
}