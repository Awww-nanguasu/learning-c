#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(){
    char* ret;
    char* a="@.";
    char p[30];
    printf("ÇëÊäÈëÄãµÄIPµØÖ·:");
    scanf("%s",p);
    for ( ret =strtok(p,a); ret!=NULL;ret=strtok(NULL,a) )
    {
        printf("%s\n",ret);
    }
    
}