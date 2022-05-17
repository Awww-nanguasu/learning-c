#include<stdio.h>
#include<string.h>
int main(){
    char arr[3]="abc";
    for (int i = 0; i < 4; i++)
    {
        printf("arr[3]:%d\n",arr[3]);
        printf("%d %d\n",arr[i],i);
    }
    
}