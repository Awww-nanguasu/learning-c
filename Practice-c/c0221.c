//��һ�����������в���ĳ����
int main()
{
    int n,i,target,ee=0;
    printf("����������ĳ���:");
    scanf("%d",&n);
    ee=n-1;
    int arr[n];
    int j=1;
    for(int i=0 ;i<=ee && j<=n;i++,j++)
    {
        printf("�������%d����:",j);
        scanf("%d",&arr[i]);
    }
    printf("������������ҵ���:");
    scanf("%d",&target);
    for(int i=0;i<=n;i++)
    {
        if(arr[i]==target && i<=ee)
        {
            printf("��%d����Ϊ����",i+1);
            break;
        }
        if(arr[i]!=target && i==n)
        {
            printf("%dδ��������",target);
            break;
        }
    }
}