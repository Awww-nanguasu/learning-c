#include<Windows.h>
#include<string.h>
#include<stdio.h>
HANDLE houtput1,houtput2;
COORD coord={0,0};
DWORD bytes=0;
int main(){
    int i=0,j=0;
    char a[20]="---------------";
    char b[20]="+++++++++++++++";
    houtput1=CreateConsoleScreenBuffer(GENERIC_WRITE,FILE_SHARE_WRITE,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);
    houtput2=CreateConsoleScreenBuffer(GENERIC_WRITE,FILE_SHARE_WRITE,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(houtput1, &cci);
    SetConsoleCursorInfo(houtput2, &cci);
    while (i<100)
    {
        j=!j;
        if (!j)
        {
            for (int k = 0; k < 10; k++)
            {
                coord.Y=k;
                WriteConsoleOutputCharacter(houtput1,a,20,coord,&bytes);
            }
            
            SetConsoleActiveScreenBuffer(houtput1);
        }
        else{
                for (int k = 0; k < 10; k++)
                {
                    coord.Y=k;
                    WriteConsoleOutputCharacter(houtput2,b,20,coord,&bytes);
                }
                SetConsoleActiveScreenBuffer(houtput2);
            }
        Sleep(500);
        i++;
    }
}
/*int main(){
    int i=0,j=0;
    char a[20]="------------------";
    char b[20]="++++++++++++++++++";
    while (i<100)
    {
        j=!j;
        if (!j)
        {
            for (int k = 0; k < 10; k++)
            {
                printf("%s",a);
                printf("\n");
            }
        }
        else{
            for (int k = 0; k < 10; k++)
            {
                printf("%s",b);
                printf("\n");
            }
        }    
        Sleep(500);
        system("cls");
        i++;
    }
}*/