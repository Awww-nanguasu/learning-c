//���100-200�������
#include <stdio.h>
#include <string.h>
int main()
{
    int i,count=0;
    for(i=100;i<=200;i++)
    {
        for(count=2;count<i;count++)
        {
            if(i%count==0)
            {
                break;
            }
        }
        if(count==i)
        {
            printf("%dΪ����",i);
        }
    }
    return 0;
}