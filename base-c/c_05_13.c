#include<stdio.h>
#include<stdlib.h>
//给定一个字符串，反转前n个字符到末尾
//1.暴力求解法
int reversal(int i,int n,char* s){
    int Left=0,Right=0;
    char* p=(char *)malloc(2*n*sizeof(char));
    for (int j = 0; j < i; j++)
    {
        p[j]=s[j];
        p[j+i]=s[j];
    }
    for (int j = 0; j < i; j++)
    {
        printf("%c",p[n+j]);
    }
    
} 
int main(){
    int n,i=0;
    char *s="HelloWorld";
    printf("请输入想反转的个数:");
    scanf("%d",&n);
    while (s[i]!=0)
    {
        i++;
    }
    if (n>i){
        printf("超出范围");
        return 0;
    }
    reversal(i,n,s);
}