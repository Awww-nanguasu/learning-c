//找出n个整数中的最大值
#include <stdio.h>
#include <string.h>
int main()
{
    printf("请规定n个数字");
    int n,i,arr[n],first;
    scanf("%d",&n);
    printf("请输入这%d个数字:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    first=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>=first)
        {
            first=arr[i];
            continue;
        }
        else
        {
            ;
        }
    }
    printf("最大数为:%d",first);
}