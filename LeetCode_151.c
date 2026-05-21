/* 

---这是我自己的初步思路，我得想法是用二维数组来写，但是数组需要malloc内存，还需要free---
---所以采用别的办法---
---由于c没有反转字符串的内置函数，所以需要自己写---
---再写一个剔除开头后尾的空格的 函数，也要具有删除词语之间多余空格的功能---
---最后就是需要for遍历每个词语，然后反转的功能---

char* reverseWords(char* s) {
    int x=0 , y=0 ;
    char arr [x][y] ;
    while ( *s ){
        while ( *s == ' ' ) {
            s++ ;
        }
        if ( *s  == '\0' ){
            break;
        }
        y = 0 ;
        while ( *s != ' ' && *s != '\0' ){
            arr[x][y++] = *s++ ;
        }
        arr[x][y] = '\0'  ;
        x++ ;
    }
}

*/

#include <stdio.h>
#include <string.h>

// 我要写一个字符串逆序的函数，英文是reverse，返回一个char ，输入 字符串s 开始的次序 结束的次序
void reverse ( char* s , int left , int right ){

    while( left < right ){
        char Trmp ;
        Trmp = s[left] ;
        s[left] = s[right] ;
        s[right] = Trmp ;
        left ++ ;
        right -- ;
    }

}

//写好了逆序函数reverse 现在需要去除首尾空格的函数 并且可以保证每个单词之间只有一个空格
//最后要返回一个新的new字符串 学习到了需要运用快慢指针 
//然后就是每隔一个单词 再将词语逆序回来
//Hello Word
//dorW olleH
//Word Hello
//实现逆序

char *reverseWords ( char *s ) {

    //先实现首位无空格 词语亮亮之间只有一个空格
    // Hello--World---Linux--
    // Hello-World-Linux
    int len = strlen(s) ;
    int slow = 0 ;
    for ( int fast = 0 ; fast < len ; fast ++ ){

        if ( s[fast] != '\0' ){

            if ( slow != 0 ){
                s[slow++] = ' ' ;
            }

            while (  fast < len  && s[fast] != ' ' ){
                s[slow++] = s[fast++] ;
            }

        }

    }
    int new_len = slow ;

    //下面要实现的就是
    // Hello-World-Linux
    // xuniL-dlroW-olleH
    s[slow++] = '\0' ;
    reverse ( s , 0 , new_len - 1 ) ;

    //下面是需要单词逆序
    // Linux-World-Hello
    int start = 0 ;
    for( int i = 0 ; i < new_len ; i ++ ) {

        if ( s[i] == ' ' || s[i] == '\0' ){
            reverse( s , start , i-1 ) ;
            start = i + 1 ;
        }

    }

    return s ;
}
