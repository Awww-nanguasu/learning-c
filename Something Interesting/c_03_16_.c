#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Win 3   //����ʤ�����Ӹ���
#define Jiange 10  //��Ҫ�������ʲô����Hang��Line����һ�¾����ˣ���Ȼ������
#define Line 10
#define Hang 10
void ShowBoard1(int MineBoard[Hang][Line]){
    int i,j;
    for ( i = 0; i < Hang; i++)
    {
        for ( j= 0; j< Line; j++)
        {
            printf("%d ",MineBoard[i][j]);
        }
        printf("\n");
    }
    
}
void Loading(int j)
{
    int i;
    char arr[17]="�����˳���Ϸ    \0";
    char arr1[17]="���ڼ�����Ϸ    \0";
    char arr2[1]="~";
    for ( i = 13;i < 16; i++)
    {
        if (j==1)
        {
            arr[i]=arr2[0];
            printf("%s\n",arr);
        }
        else if(j==2)
        {
            arr1[i]=arr2[0];
            printf("%s\n",arr1);
        }
        Sleep(500);
        system("cls");
    }
}
void DisplayBoard(int locate,int MineBoard[Hang][Line],char set)
{
    int i,j,k,count,serial,serialx,serialy;
    count=1;
    serial=(count*10);
    for ( i = 0; i < Hang; i++)
    {
        serial++;
        for ( j = 0; j < Line; j++,serial++)
        {
            serialx=serial/10;
            serialy=serial%10;
            if (MineBoard[serialx-1][serialy-1]==1)
            {
                printf("# ");
            }
            if (MineBoard[serialx-1][serialy-1]==-1)
            {
                printf("* ");
            }
            if (MineBoard[serialx-1][serialy-1]==0)
            {
                printf("%d",serial);
            }
            if (j==Line -1)
            {
                printf("\n");
                break;
            }
            printf("|");
        }
        if (i<Jiange-1)
        {
            for ( k = 0; k < Jiange; k++)
            {
                printf("---");
            }
            printf("\n");
        }
    }
}
int IsWin(int MineBoard[Hang][Line])
{
    int hang,lie,k,sum; 
    for ( hang = 0; hang < Hang; hang++)
    {
        for ( lie = 0; lie < Line; lie++)
        {
            if (MineBoard[hang][lie]!=0)
            {
                if (lie<=Line-Win+1)
                {
                    //�����ж���Ӯ
                    for (sum=0,k = 0; k < Win; k++)
                    {
                        sum+=MineBoard[hang][lie+k];
                    }
                    //��Ϊ���1�µ����Ӷ�Ӧ1,����ΧWin���������������ΪWin
                    if (sum==Win)
                    {
                        printf("���1Ӯ!\n");
                        return 1;
                    }
                    //���2��Ӧ-1��Win
                    if (sum==-Win)
                    {
                        printf("���2Ӯ!\n");
                        return 1;
                    }
                }
                //б���ж���Ӯ
                if (hang<=Hang-Win+1 && lie<=Line-Win+1)
                {
                    for (sum=0,k = 0; k < Win; k++)
                    {
                        sum+=MineBoard[hang+k][lie+k];
                    }
                    if (sum==Win)
                    {
                        printf("���1Ӯ!\n");
                        return 1;
                    }  
                    if (sum==-Win)
                    {
                        printf("���2Ӯ!\n");
                        return 1;
                    }
                }
                //�����ж���Ӯ
                if (hang<=Hang-Win+1)
                {
                    for (sum=0,k = 0; k < Win; k++)
                    {
                        sum+=MineBoard[hang+k][lie];
                    }
                    if (sum==Win)
                    {
                        printf("Ӯ!\n");
                        return 1;
                    } 
                    if (sum==-Win)
                    {
                        printf("���2Ӯ!\n");
                        return 1;
                    }
                }
                //�����ж���Ӯ
                if (hang<=Hang-Win+1 && lie>=Win-1)
                {
                    for ( sum=0,k=0; k < Win; k++)
                    {
                        sum+=MineBoard[hang+k][lie-k];
                    }
                    if (sum==Win)
                    {
                        printf("���1Ӯ!\n");
                        return 1;
                    }
                    if (sum==-Win)
                    {
                        printf("���2Ӯ!\n");
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
void game()
{
    int locate,locatex,locatey,ret,ret1=0;
    int count,player=-1;
    char player1='#'; //���1����
    char player2='*'; //���2����
    //��������ʼ����������
    int MineBoard[Hang][Line]={0};
    char ShowBoard[Hang][Line];
    //չʾ���̺����������ѭ��
    DisplayBoard(locate,MineBoard,player1);
    count=count%1-1;
    while (1)
    {
        if (count<=Hang*Line)
        {
            //�����˴���Win������ж���Ӯ
            //�ж���Ӯ
            //���1,2�������壬�˴������ظ����������Ż���
            if (player==-1)
            {
                do
                {
                    ShowBoard1(MineBoard);
                    printf("�����1������������:");
                    scanf("%d",&locate);
                    locatex=locate/10;  
                    locatey=locate%10;
                    if (MineBoard[locatex-1][locatey-1]!=0 || locate>(Hang+1)*Line || locate<=11)
                    {
                       // printf("MineBoard[%d][%d]ֵΪ:%d",locatex,locatey,MineBoard[locatex-1][]);
                        printf("���겻�Ϸ�!\n");
                        Sleep(500);
                        ret1= 1;
                    }
                    else
                    {
                        ret1= 0;
                    }
                } while (ret1);
                MineBoard[locatex-1][locatey-1]=1; //�������Ӧ����Ϊ1
                DisplayBoard(locate,MineBoard,player1);
                count++;
                player*=-1;
                if (count>=Win-1)
                {
                    ret=IsWin(MineBoard);
                    if (ret==1)
                    {
                        break;
                    }
                }
            }
            if (player==1)
            {
                do
                {
                    printf("�����2������������:");
                    scanf("%d",&locate);
                    locatex=locate/10;
                    locatey=locate%10;
                    printf("MineBoard[%d][%d]ֵΪ:",locatex,locatey);
                    if (MineBoard[locatex-1][locatey-1]!=0 || locate>(Hang+1)*Line || locate<=11)
                    {
                        printf("���겻�Ϸ�!\n");
                        Sleep(500);
                        ret1= 1;
                    }
                    else
                    {
                        ret1= 0;
                    }
//                    ret1=IfLegal(MineBoard,locate);
                } while (ret1);
//                printf("Ӧ������ĵط�Ϊ:MineBoard[%d][%d]\n",locatex-1,locatey-1);
                MineBoard[locatex-1][locatey-1]=-1;
                DisplayBoard(locate,MineBoard,player2);
                count++;
                player*=-1;
                if (count>=Win-1)
                {
                    ret=IsWin(MineBoard);
                    if (ret==1)
                    {
                        break;
                    }
                }
            }
        }
        //������������ƽ��
        else
        {
            printf("ƽ��\n");
            break;
        }
    }
}
void menu()
{
    int choose,x;
    char ch;
    do{
        printf("###########################\n");
        printf("######1.Play 0.Exit #######\n");
        printf("###########################\n");
        printf("��ѡ��:");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            //������Ϸ
            Loading(2);
            game();
            break;
        case 0:
            Loading(1);
            break;
        default:
            printf("��������ȷ������:\n");
            break;
        }
    } while (choose);
    
}
int main()
{
    menu();
}
