//������С��Ϸ���²�1-100֮�������
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
void loading()
{
    int i=23;
    char arr1[]="��Ϸ���ڼ�������ȴ�~~~   ";
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
        printf("��������µ�����:");
        scanf("%d",&guess);
        if (guess<ret)
        {
            printf("��С��\n");
        }
        else if (guess>ret)
        {
            printf("�´���\n");
        }
        else
        {
            printf("�¶���,�����:%d\n",ret);
            printf("����������ҳ��");
            Sleep(3000);
            system("cls");
            break;
        }
    }    
}
void menu()
{
    printf("###################################\n");    
    printf("#####��ʼ����:1    �˳���Ϸ:0#######\n");    
    printf("###################################\n");
}
int main()
{
    int get;
    srand((unsigned int) time(NULL));
    do
    {
        menu();
        printf("��ѡ��:");
        scanf("%d",&get);
        system("cls");
        switch (get)
        {
        case 1:
            loading();
            game();
            break;
        case 0:
            printf("�����˳���Ϸ~~");
            Sleep(2000);
            system("cls");
            break;
        default:
            printf("������0��1!\n");
            break;
        }
    }
    while (get);
//    printf("asd");
}