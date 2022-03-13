//ÓÃµİ¹é±àĞ´strlenº¯Êı
#include <string.h>
#include <stdio.h>
int len_count(char* x){
//    printf("asdadff\n");
    if (*x!='\0'){
        return 1+len_count(++x);
    }
    else
        return 0;
}
int main(){
    char arr[]="helloworld";
//    printf("asd\n");
    printf("%d\n",len_count(arr));
    return 0;
}