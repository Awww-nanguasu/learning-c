//Լɪ������:��41����Χ��һ�������ӵ�һ���˿�ʼ������������3�����˳������ʳ������˵�˳��
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
typedef struct Josephus
{
    int Data;
    struct Josephus* Pre;
    struct Josephus* Next;
}Josephus;
void InitJosephusList(Josephus* JL){
    JL->Pre=JL->Next=JL;
}
void CreatNewNode(Josephus* JL,int pos){
    Josephus* NewNode=(Josephus*)malloc(sizeof(Josephus));
    NewNode->Data=pos;
    JL->Pre->Next=NewNode;
    NewNode->Pre=JL->Pre;
    JL->Pre=NewNode;
    NewNode->Next=JL;
}
void JosephusListPop(Josephus* Cursor){
    printf("%d ",Cursor->Data);
    Cursor->Pre->Next=Cursor->Next;
    Cursor->Next->Pre=Cursor->Pre;
}
int main(){
    int count=0,j=1;
    Josephus JL;
    InitJosephusList(&JL);
    for (int i = 1; i <=41; i++)
    {
        CreatNewNode(&JL,i);
    }
    Josephus* Cursor=JL.Next;
    while (Cursor->Next!=Cursor->Pre)
    {
        if (Cursor!=&JL)
        {
            if (j==0)
            {
                JosephusListPop(Cursor);
            }
            j++;
            j%=3;
        }
        Cursor=Cursor->Next;
    }
    printf("%d",Cursor->Data);
}