#include<stdio.h>
#include<stdlib.h>
//有m个辅助，n个输出，一个队伍至少有一个辅助一个输出，每个人只能进一个队伍，问至多能组成多少个队伍?
void main(){
    int num=0,j=0,count,*na,*ma,n,m;
    printf("input:\n");
    scanf("%d",&count);
    na=(int *)malloc(count*sizeof(int));
    ma=(int *)malloc(count*sizeof(int));
    for (int i = 0; i <count; i++)
    {
        scanf("%d%d",na+i,ma+i);
    }
    printf("output:\n");
    while (j<count)
    {
        n=na[j];
        m=ma[j];
        num=0;
        if (n>=3*m || m>=3*n || n==0 || m==0)
        {
            num=(n>m?m:n);
            printf("%d\n",num);
            j++;  
            continue;
        }
        while (1)
        {
 
            if (n<m)
            {
                n=n^m;
                m=n^m;
                n=n^m;
            }        
            if (m==0 || (n!=m && n<3))
            {
                printf("%d\n",num);
                break;
            }
            if (n%3>m%2)
            {
                n=n-3;
                m=m-1;
                num++;
            }
            else{
                m=m-2;
                n=n-2;
                num++;
            }
        }
        j++;
    }
}