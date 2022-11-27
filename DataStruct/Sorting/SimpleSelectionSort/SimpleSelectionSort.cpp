#include"D:\git-workspace\learning-c\DataStruct\SeqList\SeqList.cpp"
#include"D:\git-workspace\learning-c\DataStruct\LinkList\LinkList.cpp"
void SimpleSelectionSort(SeqList* SL){//适用于顺序表
    for (int i = 0; i < SL->size; i++)
    {
        int k=i,j;
        SeqListData Mini;
        Mini=SL->a[i];
        for (j = i; j < SL->size; j++)
        {
            if (Mini>SL->a[j])
            {
                Mini=SL->a[j];
                k=j;
            }
        }
        SL->a[k]=SL->a[i];
        SL->a[i]=Mini;   
    }
}
void SimpleSelectionSort(LinkList* L){//适用于带哨兵节点的链表
    LinkList* CurPoint=L->Next;
    while (CurPoint)
    {
        LinkList* Locate=CurPoint,*CurPoint2=CurPoint;
        LinkListData Mini=CurPoint->data;
        while (CurPoint2)
        {
            if (Mini>CurPoint2->data)
            {
                Mini=CurPoint2->data;
                Locate=CurPoint2;
            }
            CurPoint2=CurPoint2->Next;
        }
        Locate->data=CurPoint->data;
        CurPoint->data=Mini;
        CurPoint=CurPoint->Next;
    }
}