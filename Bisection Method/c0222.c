//�����������в���һ����
#include <stdio.h>
#include <string.h>
int main()
{
    int left_mark,right_mark,mid_mark,target,j;
    int n,mark,i;
    printf("        ------����------\n�뱣֤�������Ϊ��������,���������ܻ���ִ���\n");
    printf("��涨�����С:");
    scanf("%d",&n);
    int arr[n];
    mark=n-1;
    for(int i=0;i<=mark;i++)
    {
        printf("�������%d����:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("������������ҵ���:");
    scanf("%d",&target);
    left_mark=0;
    right_mark=mark;
    while(left_mark<=right_mark)
    {
        mid_mark=(left_mark + right_mark)/2;
        if(arr[mid_mark] > target)
        {
            right_mark=mid_mark - 1;
            continue;
        }
        if (arr[mid_mark] < target)
        {
            left_mark=mid_mark +1;
            continue;
        }
        if(arr[mid_mark] = target)
        {
            printf("%d\n",arr[mid_mark]);
            printf("�����ҵ���Ϊ��%d���������",mid_mark+1);
            j+=1;
            break;
        }
    }
    if (j==0)
    {
        printf("δ�ҵ�");
    }
    return 0;
}
