//一个数组中，找出和等于target的两个数字，并返回它们的下标
#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,k,target,chazhi,count=0;
    printf("请输入目标值:");
    scanf("%d",&target);
    int arr[4]={2,7,11,15};
    int arr1[]={};
    for(i=0;i<4;i++)
    {
        chazhi=target-arr[i];
        for(j=0;j<4;j++)
        {
            if (chazhi==arr1[j])
            {
                printf("[%d,%d]\n",i,j);
                count++;
                break;
            }
        }
        if(count==1)
        {
            break;
        }
        arr1[k]=arr[i];
        k++;
    }
}