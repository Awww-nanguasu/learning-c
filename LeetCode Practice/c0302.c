//һ�������У��ҳ��͵���target���������֣����������ǵ��±�
#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,k,target,chazhi,count=0;
    printf("������Ŀ��ֵ:");
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