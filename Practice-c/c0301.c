//�ҳ�1-100�����к�9������
#include <string.h>
#include <stdio.h>
int main()
{
    int i;
    for(i=0;i<=100;i++)
    {
        if(i%10==9)
        {
            printf("%d\n",i);
            continue;
        }
        if (i/9==10)
        {
            printf("%d\n",i);
        }
        
    }
}