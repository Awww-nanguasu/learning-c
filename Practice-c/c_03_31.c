#include <stdio.h>
#include <math.h>
int IsPrime(int x){
    int i;
    for ( i = 2; i <=sqrt(x) ; i++)
    {
        if (x%i==0)
        {
            return 0;
        }
    }
    return 1;
    
}
int main(){
    int input,j,k,o;
    while (1)
    {
        printf("请输入一个小于1亿的偶数:");
        scanf("%d",&input);
        if (input<=100000000 && input>=4 && input%2==0)
        {
            break;
        }
        printf("不在范围内或者不为偶数，请重新输入!\n");
    }
    switch (input)
    {
    case 4:
        printf("找到了:1+3=4");
        break;
    case 6:
        printf("找到了:3+3=6");
        break;
    default:
        break;
    }
    for ( j = 3; j < input/2; j+=2)
    {
        for ( k = 2; k < sqrt(j); k++)
        {
            if (j%k==0)
            {
                break;
            }            
        }
        if (k>sqrt(j))
        {
            o=input-j;
            if (IsPrime(o)==1)
            {
                printf("找到了:%d+%d=%d\n",j,o,input);
                //break;
            }            
        }
    }
    
}