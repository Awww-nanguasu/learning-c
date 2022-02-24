//模拟用户登录账户的场景，且只能试错三次
#include <stdio.h>
#include <string.h>
int main()
{
    int i=0;
    char arr[20]="";

    for(;i<3;i++)
    {
        printf("请输入正确的密码:");
        scanf("%s",arr);
        if(strcmp(arr,"1234567")==0)
        {
            printf("密码正确");
            break;
        }
        else
        {
            printf("密码错误,请重新输入\n");
        }
    }
}