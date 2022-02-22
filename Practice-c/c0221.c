//在一个有序数组中查找某个数
int main()
{
    int n,i,target,ee=0;
    printf("请输入数组的长度:");
    scanf("%d",&n);
    ee=n-1;
    int arr[n];
    int j=1;
    for(int i=0 ;i<=ee && j<=n;i++,j++)
    {
        printf("请输入第%d个数:",j);
        scanf("%d",&arr[i]);
    }
    printf("请输入你想查找的数:");
    scanf("%d",&target);
    for(int i=0;i<=n;i++)
    {
        if(arr[i]==target && i<=ee)
        {
            printf("第%d个数为所求",i+1);
            break;
        }
        if(arr[i]!=target && i==n)
        {
            printf("%d未在数组中",target);
            break;
        }
    }
}