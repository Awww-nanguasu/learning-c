#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
int DetectNextDirection(int SecDirection[3],int* Cat,int MainDirection){
    for (int i = 0; i < 3; i++)
    {
        if(*(Cat+SecDirection[i])==3){
            ;
        }
        else{
            return MainDirection;
        }
    }
    return MainDirection+1;    
}
int NextMainDirection(int MainDirection,int* Cat){
    int NorthDirection[3]={-12,-11,-10};
    int WestDirection[3]={-12,-1,10};
    int SouthDirection[3]={10,11,12};
    int EastDirection[3]={-10,1,12};
    switch (MainDirection)
    {
    case 0:
        return DetectNextDirection(NorthDirection,Cat,MainDirection);
    case 1:
        return DetectNextDirection(WestDirection,Cat,MainDirection);
    case 2:
        return DetectNextDirection(SouthDirection,Cat,MainDirection);
    default:
        return DetectNextDirection(EastDirection,Cat,MainDirection);
    }
}
void InitShowBoard(int ShowBoard[11][11]){
    for (int i = 0; i < 11; i++)
    {
        ShowBoard[i][0]=8;
        ShowBoard[i][10]=8;
    }
    for (int i = 0; i < 11; i++)
    {
        ShowBoard[0][i]=8;
        ShowBoard[10][i]=8;
    }
}
int IfWays(int* Cat){
    int Direction[8]={-12,-11,-10,-1,1,10,11,12};
    int count=0;
    for (int i = 0; i < 8; i++)
    {
        if (*(Cat+Direction[i])<2)
        {
            count++;
        }
    }
    return count;
}
void DisPlayBorad(int ShowBoard[11][11])
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            switch (ShowBoard[i][j])
            {
            case 0:
                printf("\033[1;30;40m[ ]\033[0m");
                break;
            case 1:
                printf("\033[1;36;40m< >\033[0m",i,j);
                break;    
            case 3:
                printf("\033[1;32;47m * \033[0m");
                break;
            case 8:
                printf("\033[1;30;40m[#]\033[0m");
                break;
            case 9:
                printf("\033[1;37;40m[@]\033[0m");
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
}
int SecDirection(int MainDirection,int* Cat){
    int NorthDirection[3]={-12,-11,-10};
    int WestDirection[3]={-12,-1,10};
    int SouthDirection[3]={10,11,12};
    int EastDirection[3]={-10,1,12};
    int y;
    switch (MainDirection)
    {
    case 0:
        do
        {
            y=rand()%3;
        } while (*(Cat+NorthDirection[y])==3);
        return NorthDirection[y];
    case 1:
        do
        {
            y=rand()%3;
        } while (*(Cat+WestDirection[y])==3);
        return WestDirection[y];
    case 2:
        do
        {
            y=rand()%3;
        } while (*(Cat+SouthDirection[y])==3);
        return SouthDirection[y];
    default:
        do
        {
            y=rand()%3;
        } while (*(Cat+EastDirection[y])==3);
        return EastDirection[y];
    }
}
int DetectDirection(){
    int MainDirection=rand()%4;
    return MainDirection;
}
int* PlayerMove(int a,int* Player){
    if (*(Player+a)!=3 && *(Player+a)!=9)
    {
        *(Player+a)=1;
    }
    if (*Player!=3 && *Player!=9)
    {
        *Player=0;  
    }
    Player+=a;
    return Player;
}
int* CatAction(int *Cat,int Direction,int ShowBoard[11][11]){
    if (*(Cat+Direction)==8)
    {
        *(Cat+Direction)=9;
        *Cat=0;
        Cat+=Direction;
        system("cls");
        DisPlayBorad(ShowBoard);
        printf("ƒ„ ‰¡À");
        return 0;
    }
    *(Cat+Direction)=9;
    *Cat=0;
    Cat+=Direction;

    return Cat;
}
int* Action(char Input,int ShowBoard[11][11],int* Player,int *Cat)
{
    switch (Input)
    {
    case 27:
        break;
    case 101:
        if (*Player!=3 && *Player!=9)
        {
            *Player=3;
            return Player;
        }
        return 0;
        break;
    case 100://d
        if (((Player+1)<=(&ShowBoard[10][10])))
        {
            return PlayerMove(1,Player);
        }
        return Player;
        break;
    case 97://a
        if (((Player-1)>=(&ShowBoard[0][0])))
        {
            return PlayerMove(-1,Player);
        }
        return Player;
        break;
    case 115:
        if (((Player+11)<=(&ShowBoard[10][10])))
        {
            return PlayerMove(11,Player);
        }
        return Player;
        break;
    case 119://w
        if(((Player-11)>=(&ShowBoard[0][0])))
        {
            return PlayerMove(-11,Player);
        }
        return Player;
        break;
    default:
        break;
    }
}
int main()
{
    char Input;
    int x,y,MainDirection,*tmp,Direction;
    int *Player,*Cat;
    HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CurSorInfo;
    GetConsoleCursorInfo(handle,&CurSorInfo);
    CurSorInfo.bVisible=FALSE;
    SetConsoleCursorInfo(handle,&CurSorInfo);
    int ShowBoard[11][11]={0};
    InitShowBoard(ShowBoard);
    ShowBoard[5][5]=9;
    ShowBoard[3][3]=1;
    Player=&ShowBoard[3][3];
    Cat=&ShowBoard[5][5];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 5; i++)
    {
        x=rand()%11;
        y=rand()%11;
        ShowBoard[x][y]=3;
    }
    MainDirection=DetectDirection();
    DisPlayBorad(ShowBoard);
    while (Input!=27)
    {
        if (kbhit())
        {
            Input=getch();
            system("cls");
            tmp=Player;
            Player=Action(Input,ShowBoard,Player,Cat);
            DisPlayBorad(ShowBoard);
            if (Input==101 && Player!=0)
            {
                MainDirection=NextMainDirection(MainDirection,Cat);
                Direction=SecDirection(MainDirection,Cat);
                Cat=CatAction(Cat,Direction,ShowBoard);
                if (Cat==0)
                {
                    return 0;
                }
                Sleep(100);
                system("cls");
                DisPlayBorad(ShowBoard);
                continue;
            }
            if(Player==0){
                Player=tmp;
            }
        }
    }
    return 0;
}