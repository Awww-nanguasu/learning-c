//在有序数组中查找一个数
#include <stdio.h>
#include <string.h>
int main()
{
    int left_mark,right_mark,mid_mark,target,j;
    int n,mark,i;
    printf("        ------声明------\n请保证您输入的为有序数组,否则结果可能会出现错误\n");
    printf("请规定数组大小:");
    scanf("%d",&n);
    int arr[n];
    mark=n-1;
    for(int i=0;i<=mark;i++)
    {
        printf("请输入第%d个数:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("请输入您想查找的数:");
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
            printf("您所找的数为第%d个输入的数",mid_mark+1);
            j+=1;
            break;
        }
    }
    if (j==0)
    {
        printf("未找到");
    }
    return 0;
}
