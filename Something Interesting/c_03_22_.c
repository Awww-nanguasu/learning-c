#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void DisplayBoard(char ShowBoard[ROWS][COLS]){
    int i,j;
    printf("  ");
    for ( i = 1; i <=ROW; i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for ( i = 1; i <= ROW; i++){
        printf("%d ",i);
        for ( j = 1; j <= COL; j++){
            printf("%c ",ShowBoard[i][j]);
        }
        printf("\n");
    }
    
}
int Explore(char MineBoard[ROWS][COLS],int x,int y){
//    int ret=0;
    return MineBoard[x-1][y-1]+
    MineBoard[x-1][y]+MineBoard[x-1][y+1]+
    MineBoard[x][y-1]+MineBoard[x][y]+
    MineBoard[x][y+1]+MineBoard[x+1][y-1]+
    MineBoard[x+1][y]+MineBoard[x+1][y+1]-8*'0';
}
int FindBoom(char MineBoard[ROWS][COLS],char ShowBoard[ROWS][COLS]){
    int n,x,y,ret,count=0;
    printf("请输入你选的坐标:");
    while (1)
    {
        scanf("%d",&n);
        x=n/10;
        y=n%10;
        if (x>=1 && x<=ROW && y>=1 &&y<=COL){
            if (count==71)
            {
                return count;
            }
            
            if (MineBoard[x][y]=='1')
            {
                printf("你被炸死了");
                DisplayBoard(MineBoard);
                return 1;
            }
            if (MineBoard[x][y]=='0')
            {
                ret=Explore(MineBoard,x,y);
                printf("%d\n",ret);
                ShowBoard[x][y]=ret;
                DisplayBoard(ShowBoard); 
                count++;
                return 0;
            }
        }
        else{
            printf("请重新输入:");
        }
        
    }
    
    
}
void BoomSet(char MineBoard[ROWS][COLS]){
    int x,y,count=1;
    while (count<=10){
        x=rand()%ROW+1;
        y=rand()%COL+1;
        if (MineBoard[x][y]=='0')
        {
            MineBoard[x][y]='1';
            count++;
        }
        else
            continue;
    }
//    DisplayBoard(MineBoard);
}
void InitBoard(char MineBoard[ROWS][COLS],char set){
    int i,j,k;
    for ( i = 0; i < ROWS; i++){
        for ( j = 0; j < COLS; j++){
            MineBoard[i][j]=set;
            //printf("%c",MineBoard[i][j]);
        }
        //printf("\n");
    }
    
}
void game(){
    int count,ret=0;
    //创建棋盘
    char MineBoard[ROWS][COLS]={0};
    char ShowBoard[ROWS][COLS]={0};
    //初始化棋盘
    InitBoard(MineBoard,'0');
    InitBoard(ShowBoard,'*');
    //展示棋盘
    DisplayBoard(ShowBoard);
    //布置雷
//    printf("asd");
    BoomSet(MineBoard);
    //开始扫雷
    while (count!=81)
    {
        count++;
        ret=FindBoom(MineBoard,ShowBoard);
        if (ret==1)
        {
            break;
        }
    }
}
void menu(){
    int choose;
    do{
        printf("##############################\n");
        printf("########1.Play 0.Exit#########\n");
        printf("##############################\n");
        printf("请输入你的选择:");
        scanf("%d",&choose);
        switch (choose){
        case 1:
            game();
            break;
        case 0:

            break;
        default:
            printf("请输入正确的数字\n");
            break;
        }
    } while (choose);
}
void main(){
    srand((unsigned)time(NULL));
    menu();
}

