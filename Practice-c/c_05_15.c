#include<stdio.h>
int My_strlen(int n,char *s){
    if(*(s+n)!=0)
    {
        return My_strlen(n+1,s)+1;
    }
    else
        return 0;
}
int main(){
    char s[30]="HelloWorldASD";
    int a=My_strlen(0,s);
    printf("%d",a);
}