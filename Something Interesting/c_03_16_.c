 #include <stdio.h>
#include <stdlib.h>
#define Win 5   //ʤ��ʤ�����Ӹ���
#define Jiange 10  //��Ҫ�������ʲô����Hang��Line����һ�¾����ˣ���Ȼ������
#define Line 10
#define Hang 10
void DisplayBoard(int locate,int MineBoard[Hang][Line],char set){
    int i,j,k,count,serial,serialx,serialy;
    count=1;
    serial=(count*10);
    for ( i = 0; i < Hang-1; i++)
    {
        serial++;
        for ( j = 0; j < Line; j++,serial++)
        {
            serialx=serial/10;
            serialy=serial%10;
            if (MineBoard[serialx-1][serialy-1]!=0)
            {
                printf("%c ",set);
            }
            else
                printf("%d",serial);
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
//    printf("���������131��:%d\n",MineBoard[12][0]);
}
int IsWin(int MineBoard[Hang][Line]){
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
                    //���2��Ӧ2��Win
                    if (sum==2*Win)
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
                        sum+=MineBoard[hang+k][lie+k];
                    }
                    if (sum==Win)
                    {
                        printf("���1Ӯ!\n");
                        return 1;
                    }  
                    if (sum==2*Win)
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
                        sum+=MineBoard[hang+k][lie];
                    }
                    if (sum==Win)
                    {
                        printf("Ӯ!\n");
                        return 1;
                    } 
                    if (sum==2*Win)
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
                        printf("Ӯ!\n");
                        return 1;
                    }
                    if (sum==2*Win)
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
void game(){
    int locate,locatex,locatey,ret=0;
    int count,player=-1;
    char player1='#'; //���1����
    char player2='*'; //���2����
    //��������ʼ����������
    int MineBoard[Hang][Line]={0};
    char ShowBoard[Hang][Line];
    //չʾ���̺����������ѭ��
    DisplayBoard(locate,MineBoard,player1);
    while (1)
    {
        if (count<=Hang*Line)
        {
            //�����˴���Win������ж���Ӯ
            if (count>=Win-1)
            {
                //�ж���Ӯ
                ret=IsWin(MineBoard);
                if (ret==1)
                {
                    break;
                }
            }
            //���1,2�������壬�˴������ظ����������Ż���
            if (player==-1)
            {
                printf("�����1������������:");
                scanf("%d",&locate);
                locatex=locate/10;  
                locatey=locate%10;
                MineBoard[locatex-1][locatey-1]=1; //�������Ӧ����Ϊ1
                DisplayBoard(locate,MineBoard,player1);
                count++;
                player*=-1;
            }
            if (player==1)
            {
                printf("�����2������������:");
                scanf("%d",&locate);
                locatex=locate/10;
                locatey=locate%10;
                MineBoard[locatex-1][locatey-1]=2;
                DisplayBoard(locate,MineBoard,player2);
                count++;
                player*=-1;
            }
        }
        //������������ƽ��
        else{
            printf("ƽ��\n");
        }
    }
}
void menu(){
    int choose,x;
    do
    {
        printf("###########################\n");
        printf("######1.Play 0.Exit #######\n");
        printf("###########################\n");
        printf("��ѡ��:");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            //������Ϸ
            game();
            break;
        case 0:
            //�˳���Ϸ��������д
            break;
        default:
            printf("��������ȷ������:\n");
            break;
        }
    } while (choose);
    
}
int main(){
    menu();
}