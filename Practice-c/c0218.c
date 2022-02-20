#include <stdio.h>
#include <string.h>
//int main()
//{
//    for(int i,j = 1;i=0;i++,j++)
//    {
//        j++;
//        printf("%d\n",j);
//    }
//    //int i=1;
//    do
//    {
//        printf("%d\n",i);
//        i++;
//    } 
//    while (i<=10);
//    
//    return 0;
//}
//计算阶乘
//int main()
//{
//    int i,sum=0;
//    printf("请输入你想计算的阶乘:");
//    scanf("%d",&sum);
//    i=sum-1;
//    while(i!=1)
//    {
//        sum=sum*i;
//        i--;
//    }
//    printf("%d",sum);
//}
//计算1！+2！+……+n!
int main()
{
    int sum,n,i=0;
    static int sumzong=0;
    printf("请输入n的值:");
    scanf("%d",&n);
    for(;n!=0;n--)
    {
        sum=n;
        i=sum-1;
        while(i>1)
        {
            sum=sum*i;
            i--;
        }
        sumzong+=sum;
    }
    printf("%d\n",sumzong);
}