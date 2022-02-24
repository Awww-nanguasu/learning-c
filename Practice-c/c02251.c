//求最大公因数
#include <stdio.h>
#include <string.h>
int main()
{
    int a,b,c;
    printf("请输入两个数:");
    scanf("%d%d",&a,&b);
    c=a%b;
    while(c!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    printf("最大公约数为%d",a);
}