#include <stdio.h>
#include <stdbool.h>

bool canPlaceFlowers ( int *flowerbed , int flowerbedSize , int n ) {

    int i = 0 ;
    while ( i < flowerbedSize ){
        if ( flowerbed [i] == 0 && ( i == 0 || flowerbed [ i - 1 ] == 0 ) && ( i == flowerbedSize - 1 || flowerbed [ i + 1 ] == 0 )) {
            flowerbed [i] = 1 ; //  将i==0放在前面   防止越界访问 f[-1]
            n -- ;
            i += 2 ;
            if ( n < 0 ) return true ;
        }
        else if ( flowerbed[ i ] == 1 ) {
            i += 2 ;
        }
        else {
            i ++ ;
        }
    }
    return n <= 0 ;
    
}