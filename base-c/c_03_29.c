#include <stdio.h>
int main(){
    int n,i,count=0;
    scanf("%d",&n);
    for ( i = 0; i < 32; i++)
    {
        if ((n>>i)&1==1)
        {
            count++;
           // printf("%d\n",count);
        }
    }
    printf("%d\n",count);
}