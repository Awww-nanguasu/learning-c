#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
{
    char input[]="";
    system("color 4");
    system("shutdown -s -t 60");
    printf("!!!!------警告------!!!! \n");
    printf("您的电脑将在一分钟后关机\n");
    printf("请输入“我是猪”来解决这个危机\n");

    while(1)
    {
        printf("请输入:");
        scanf("%s",input);
        if(strcmp(input,"我是猪")==0)
        {
            system("color 7");
            system("shutdown -a");
            printf("危机解除");
            break;
        }
        else
        {
            printf("你确定要这么做？我再给你亿次机会\n");
        }
    }
}