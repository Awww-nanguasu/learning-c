#include"DDList.h"
DDList* CreatNewNode(DDListData x){
    DDList* NewNode=(DDList*)malloc(sizeof(DDList));
    NewNode->data=x;
    NewNode->Next=NULL;
    NewNode->PrvPoint=NULL;
    return NewNode;
}
void DDListInit(DDList* Head){
    if (Head!=NULL)
    {
        Head->Next=Head->PrvPoint=Head;
        Head->data=0; 
    }
}
void DDListPushFront(DDList* Head,DDListData x){
    DDList* NewNode=CreatNewNode(x);
    NewNode->Next=Head->Next;
    Head->Next=NewNode;
    NewNode->PrvPoint=Head;
    NewNode->Next->PrvPoint=NewNode;//不管双向链表是否为空，都可以用这套逻辑
}
void DDListPushBack(DDList* Head,DDListData x){
    DDList* NewNode=CreatNewNode(x);
    Head->PrvPoint->Next=NewNode;
    NewNode->PrvPoint=Head->PrvPoint;
    Head->PrvPoint=NewNode;
    NewNode->Next=Head;
}
void DDListPopFront(DDList* Head){
    Head->Next=Head->Next->Next;
    Head->Next->PrvPoint=Head;
}
void DDListPopBack(DDList* Head){
    Head->PrvPoint=Head->PrvPoint->PrvPoint;
    Head->PrvPoint->Next=Head;
}
void DDListInsert(DDList* Head,DDListData x,int Pos){
    DDList* CurPoint=Head;
    for (int i = 0; (i < Pos-1) && CurPoint->Next!=Head; i++)
    {
        CurPoint=CurPoint->Next;
    }
    DDList* NewNode=CreatNewNode(x);
    NewNode->Next=CurPoint->Next;
    CurPoint->Next->PrvPoint=NewNode;
    CurPoint->Next=NewNode;
    NewNode->PrvPoint=CurPoint;
}
void DDListErase(DDList* Head,int Pos){
    DDList* CurPoint=Head;
    for (int i = 0; (i < Pos-1)&&CurPoint->Next->Next!=Head; i++)
    {
        CurPoint=CurPoint->Next;
    }
    CurPoint->Next=CurPoint->Next->Next;
    CurPoint->Next->PrvPoint=CurPoint;
}