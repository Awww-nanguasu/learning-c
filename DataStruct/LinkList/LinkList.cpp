#include"LinkList.h"
LinkList* AddLinkListNode(LinkListData x){
    LinkList* NewNode=(LinkList*)malloc(sizeof(LinkList));
    if (NewNode==NULL)
    {
        printf("ÉêÇë½ÚµãÊ§°Ü");
    }
    NewNode->data=x;
    NewNode->Next=NULL;
    return NewNode;
}
void LinkListPushFront(LinkList** CurPoint,LinkListData x){
    LinkList* NewNode=AddLinkListNode(x);
    if (*CurPoint==NULL)
    {
        *CurPoint=NewNode;;
    }
    else
        NewNode->Next=*CurPoint;
        *CurPoint=NewNode;
}
void LinkListPushBack(LinkList* CurPoint,LinkListData x){
    while (CurPoint->Next!=NULL)
    {
        CurPoint=CurPoint->Next;
    }
    CurPoint->Next=AddLinkListNode(x);
}
void LinkListPopFront(LinkList** CurPoint){
    if ((*CurPoint)->Next==NULL || *CurPoint==NULL)
    {
        *CurPoint=NULL;
    }
    else{
        *CurPoint=(*CurPoint)->Next;
    }
}
void LinkListPopBack(LinkList* CurPoint){
    while (CurPoint->Next->Next!=NULL)
    {
        CurPoint=CurPoint->Next;
    }
    CurPoint->Next=NULL;
}
void LinkListInsert(LinkList* CurPoint,LinkListData x,int pos){
    if (pos<=1||CurPoint==NULL)
    {
        LinkListPushFront(&CurPoint,x);
    }
    else 
    {
        LinkList* NewNode=AddLinkListNode(x);
        for (int i = 1; i < pos-1 && CurPoint->Next!=NULL; i++)
        {
            CurPoint=CurPoint->Next;
        }
        LinkList* AddNewNode=CurPoint->Next;
        CurPoint->Next=NewNode;
        NewNode->data=x;
        NewNode->Next=AddNewNode;
    }
}
void LinkListErase(LinkList* CurPoint,LinkListData pos){
    if (pos<=1 ||  CurPoint==NULL)
    {
        LinkListPopFront(&CurPoint);
    }
    else 
    {
        for (int i = 1; i < pos-1 && CurPoint->Next!=NULL; i++)
        {
            CurPoint=CurPoint->Next;
        }
        if (CurPoint->Next==NULL)
        {
            LinkListPopBack(CurPoint);
        }
        else{
            CurPoint->Next=CurPoint->Next->Next;
        }
    }
}