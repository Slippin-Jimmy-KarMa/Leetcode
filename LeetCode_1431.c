#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int get_Max ( int *candies , int candiesSize ) {

    int max = candies[0] ;

    for ( int i = 1 ; i < candiesSize ; i ++ ) {
        if ( candies[i] > max ) max = candies[i] ;
    }
    
    return max ;

}

bool * kidswithCandies ( int *candies , int candiesSize , int extraCandies , int *returnSize ) {
    
    int max = get_Max( candies , candiesSize ) ;
    bool *array = (bool*) malloc ( candiesSize * sizeof (bool) ) ; 

    for ( int i = 0 ; i < candiesSize ; i ++) {
        int NewCandies = candies[i] + extraCandies ;
        array[i] = ( NewCandies >= max ) ;
    }
    *returnSize = candiesSize;

    return array ;
}

int main ()
{
    int candies[5] = { 2 , 3 , 5 , 1 , 3 } ;
    int candiesSize = 5 ;
    int extraCandies = 3 ;
    int returnSize ;

    bool *array = kidswithCandies ( candies , candiesSize , extraCandies , &returnSize ) ;
    
    bool *p = array ;
    for ( int i = 0 ; i < returnSize ; i ++ ) {
        printf ( "%d" , *( p + i )) ;
    }
    free (array) ;

    return 0 ;
}