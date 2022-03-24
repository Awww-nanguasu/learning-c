 #include <stdio.h>
#include <stdlib.h>
#define Win 5   //胜利胜利棋子个数
#define Jiange 10  //不要问这个是什么，跟Hang和Line保持一致就行了，不然你试试
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
//    printf("下子数组第131个:%d\n",MineBoard[12][0]);
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
                    //横向判断输赢
                    for (sum=0,k = 0; k < Win; k++)
                    {
                        sum+=MineBoard[hang][lie+k];
                    }
                    //因为玩家1下的棋子对应1,若周围Win个棋子相连，则和为Win
                    if (sum==Win)
                    {
                        printf("玩家1赢!\n");
                        return 1;
                    }
                    //玩家2对应2倍Win
                    if (sum==2*Win)
                    {
                        printf("玩家2赢!\n");
                        return 1;
                    }
                }
                //竖向判断输赢
                if (hang<=Hang-Win+1)
                {
                    for (sum=0,k = 0; k < Win; k++)
                    {
                        sum+=MineBoard[hang+k][lie+k];
                    }
                    if (sum==Win)
                    {
                        printf("玩家1赢!\n");
                        return 1;
                    }  
                    if (sum==2*Win)
                    {
                        printf("玩家2赢!\n");
                        return 1;
                    }
                }
                //斜向判断输赢
                if (hang<=Hang-Win+1 && lie<=Line-Win+1)
                {
                    for (sum=0,k = 0; k < Win; k++)
                    {
                        sum+=MineBoard[hang+k][lie];
                    }
                    if (sum==Win)
                    {
                        printf("赢!\n");
                        return 1;
                    } 
                    if (sum==2*Win)
                    {
                        printf("玩家2赢!\n");
                        return 1;
                    }
                }
                //左下判断输赢
                if (hang<=Hang-Win+1 && lie>=Win-1)
                {
                    for ( sum=0,k=0; k < Win; k++)
                    {
                        sum+=MineBoard[hang+k][lie-k];
                    }
                    if (sum==Win)
                    {
                        printf("赢!\n");
                        return 1;
                    }
                    if (sum==2*Win)
                    {
                        printf("玩家2赢!\n");
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
    char player1='#'; //玩家1棋子
    char player2='*'; //玩家2棋子
    //创建并初始化两个棋盘
    int MineBoard[Hang][Line]={0};
    char ShowBoard[Hang][Line];
    //展示棋盘后进入输坐标循环
    DisplayBoard(locate,MineBoard,player1);
    while (1)
    {
        if (count<=Hang*Line)
        {
            //当下了大于Win个棋后判断输赢
            if (count>=Win-1)
            {
                //判断输赢
                ret=IsWin(MineBoard);
                if (ret==1)
                {
                    break;
                }
            }
            //玩家1,2轮流下棋，此处代码重复，交给你优化了
            if (player==-1)
            {
                printf("请玩家1输入下棋坐标:");
                scanf("%d",&locate);
                locatex=locate/10;  
                locatey=locate%10;
                MineBoard[locatex-1][locatey-1]=1; //让数组对应坐标为1
                DisplayBoard(locate,MineBoard,player1);
                count++;
                player*=-1;
            }
            if (player==1)
            {
                printf("请玩家2输入下棋坐标:");
                scanf("%d",&locate);
                locatex=locate/10;
                locatey=locate%10;
                MineBoard[locatex-1][locatey-1]=2;
                DisplayBoard(locate,MineBoard,player2);
                count++;
                player*=-1;
            }
        }
        //当棋盘下满后平局
        else{
            printf("平局\n");
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
        printf("请选择:");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            //进行游戏
            game();
            break;
        case 0:
            //退出游戏动画，待写
            break;
        default:
            printf("请输入正确的数字:\n");
            break;
        }
    } while (choose);
    
}
int main(){
    menu();
}