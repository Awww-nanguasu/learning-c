//猜数字小游戏，猜测1-100之间的数字
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
void loading()
{
    int i=23;
    char arr1[]="游戏正在加载中请等待~~~   ";
    char arr2[]="~";
    while (i<=25)
    {
        arr1[i]=arr2[0];
        printf("%s\n",arr1);
        Sleep(1000);
        system("cls");
        i++;
    }
    

}
void game()
{
    int ret,guess;
    ret=rand()%100+1;
    while(1)
    {
        printf("请输入你猜的数字:");
        scanf("%d",&guess);
        if (guess<ret)
        {
            printf("猜小了\n");
        }
        else if (guess>ret)
        {
            printf("猜大了\n");
        }
        else
        {
            printf("猜对了,结果是:%d\n",ret);
            printf("即将返回主页面");
            Sleep(3000);
            system("cls");
            break;
        }
    }    
}
void menu()
{
    printf("###################################\n");    
    printf("#####开始游玩:1    退出游戏:0#######\n");    
    printf("###################################\n");
}
int main()
{
    int get;
    srand((unsigned int) time(NULL));
    do
    {
        menu();
        printf("请选择:");
        scanf("%d",&get);
        system("cls");
        switch (get)
        {
        case 1:
            loading();
            game();
            break;
        case 0:
            printf("即将退出游戏~~");
            Sleep(2000);
            system("cls");
            break;
        default:
            printf("请输入0或1!\n");
            break;
        }
    }
    while (get);
//    printf("asd");
}