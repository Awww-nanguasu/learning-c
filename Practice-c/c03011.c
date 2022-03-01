//计算1/1+1/2+……+1/n
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    float i,j;
    float sum=0;
    printf("请输入n的值:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        j=1/i;
        sum+=j;
    }
    printf("%f",sum);
    return 0;
}