#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
{
    char input[]="";
    system("color 4");
    system("shutdown -s -t 60");
    printf("!!!!------����------!!!! \n");
    printf("���ĵ��Խ���һ���Ӻ�ػ�\n");
    printf("�����롰��������������Σ��\n");

    while(1)
    {
        printf("������:");
        scanf("%s",input);
        if(strcmp(input,"������")==0)
        {
            system("color 7");
            system("shutdown -a");
            printf("Σ�����");
            break;
        }
        else
        {
            printf("��ȷ��Ҫ��ô�������ٸ����ڴλ���\n");
        }
    }
}