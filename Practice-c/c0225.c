//ģ���û���¼�˻��ĳ�������ֻ���Դ�����
#include <stdio.h>
#include <string.h>
int main()
{
    int i=0;
    char arr[20]="";

    for(;i<3;i++)
    {
        printf("��������ȷ������:");
        scanf("%s",arr);
        if(strcmp(arr,"1234567")==0)
        {
            printf("������ȷ");
            break;
        }
        else
        {
            printf("�������,����������\n");
        }
    }
}