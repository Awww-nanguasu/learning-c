#include <string.h>
#include <stdio.h>
#include <math.h>
//��ַ����
//int exchange(int* x,int* y)
//{
//    int tmp;
//    tmp=*x;
//    *x=*y;
//    *y=tmp;
//}
//int main()
//{
//    int a,b;
//    a=1;
//    b=7;
//    int* ap=&a;
//    int* bp=&b;
//    exchange(ap,bp);
//    printf("a:%d b:%d",a,b);
//}
//------------------------------
//��ֵ����
int is_prime(int x)
{
    int i;
    for(i=2;i<sqrt(x);i++)
    {
        if(x%i==0)
        {
            return 0;
        }
        else if(x%i!=0 && i+1>=sqrt(x))
        {
            return 1;
        }
    }
}
int main()
{
    int n;
    printf("������n��ֵ");
    scanf("%d",&n);
    if(is_prime(n)==1)
        printf("����Ϊ����");
    else
    {
        printf("����");
    }
}