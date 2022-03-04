#include <stdio.h>
#include <string.h>
int main()
{
    int i,n;
    for ( i = 1; i < 10; i++)
    { 
        for ( n = 1; n <=i; n++)
        {
            printf("%d*%d=%2d ",n,i,i*n);
        }
        printf("\n");
    }
    
}