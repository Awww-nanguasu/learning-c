//´òÓ¡Ñî»ÔÈý½Ç
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,*p,count,k=0;
    scanf("%d",&n);
    p=(int*)malloc(n*n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(p+n*i)=1;
        for (int j = 1; j <=i; j++)
        {
            if (j==i)
            {
                *(p+n*i+j)=1;
                break;
            }
            if (i>=1)
            {
                *(p+n*i+j)=*(p+n*(i-1)+j)+*(p+n*(i-1)+j-1);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        k=n-i;
        while (k>0)
        {
            printf(" ");
            k--;
        }
        for (int j = 0; j <= i; j++)
        {
            printf("%d ",*(p+n*i+j));
        }
        printf("\n");
    }
}