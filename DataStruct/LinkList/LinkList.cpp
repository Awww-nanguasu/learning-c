#include"LinkList.h"
LinkList* AddLinkListNode(LinkListData x){
    LinkList* NewNode=(LinkList*)malloc(sizeof(LinkList));
    NewNode->data=x;
    if (NewNode==NULL)
    {
        printf("ÉêÇë½ÚµãÊ§°Ü");
    }
    return NewNode;
}
void LinkListPushFront(LinkList** CurPoint,LinkListData x){
    LinkList* NewNode=AddLinkListNode(x);
    NewNode->Next=*CurPoint;
    *CurPoint=NewNode;
}
void LinkListPushBack(LinkList* CurPoint,LinkListData x){
    while (CurPoint->Next!=NULL)
    {
        CurPoint=CurPoint->Next;
    }
    CurPoint->Next=AddLinkListNode(x);
    CurPoint->Next->Next=NULL;
}
void LinkListPopFront(LinkList** CurPoint){
    assert(*CurPoint);
    if ((*CurPoint)->Next==NULL)
    {
        *CurPoint=NULL;
    }
    else{
        *CurPoint=(*CurPoint)->Next;
    }
}