#include<stdio.h>
#include<stdlib.h>
//����һ���ַ�������תǰn���ַ���ĩβ
//1.������ⷨ
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
    printf("�������뷴ת�ĸ���:");
    scanf("%d",&n);
    while (s[i]!=0)
    {
        i++;
    }
    if (n>i){
        printf("������Χ");
        return 0;
    }
    reversal(i,n,s);
}