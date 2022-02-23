//π“≤ –°”Œœ∑
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
int main()
{
    int left_mark,right_mark,n=0;
    char arr1[]="           ";
    char arr2[]="Hello World";
    n=strlen(arr1);
    while (left_mark <=n)
    {
        printf("%s\n",arr1);
        right_mark=n-1;
        arr1[left_mark]=arr2[left_mark];
        right_mark--;
        Sleep(400);
        if(left_mark<n)
        {
            system("cls");
        }
        left_mark++;
    }
    return 0;
}