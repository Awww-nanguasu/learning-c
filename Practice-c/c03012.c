//�ҳ�n�������е����ֵ
#include <stdio.h>
#include <string.h>
int main()
{
    printf("��涨n������");
    int n,i,arr[n],first;
    scanf("%d",&n);
    printf("��������%d������:",n);
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
    printf("�����Ϊ:%d",first);
}