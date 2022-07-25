//双向链表实现维吉尼亚加密法
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct Vigenere
{
    struct Vigenere* Prv;
    struct Vigenere* Next;
    char Data;
}Vigenere;
void InitVigenere(Vigenere* V){
    V->Prv=V->Next=V;
}
void LinkNewNode(Vigenere* VCursor){
    static int i=65;
    Vigenere* NewNode=(Vigenere*)malloc(sizeof(Vigenere));
    VCursor->Next=NewNode;
    NewNode->Prv=VCursor;
    NewNode->Next=NULL;
    NewNode->Data=(char)i;
    i++;
}
int Encryption(char Word[26],Vigenere V,int Key[26]){
    static int i=0;
    int j=0;
    Key[i]=rand()%3;
    j=Key[i];
    j+=(V.Data-65);
    for (int k = 0; k < j; k++)
    {
        V=*(V.Next);
    }
    Word[i]=V.Data;
    i++;
}
int main(){
    Vigenere V;
    V.Data=65;
    Vigenere* VCursor=&V;
    int Key[26]={0};
    srand((unsigned)time(NULL));
    for (int i = 0; i < 25; i++)
    {
        LinkNewNode(VCursor);
        VCursor=VCursor->Next;
    }
    VCursor->Next=&V;
    V.Prv=VCursor;
    printf("请输入你想加密的话(长度不超过25):\n");
    char Word[26];
    fgets(Word,26,stdin);
    printf("%s\n",Word);
    VCursor=&V;
    for (int k = 0; k < 26; k++)
    {
        Encryption(Word,V,Key);
    }
//    printf("%c ",VCursor->Data);
    printf("%s ",Word);
    printf("\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%d",Key[i]);
    }  
}
