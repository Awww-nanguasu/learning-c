#include"D:\git-workspace\learning-c\DataStruct\LinkList\LinkList.cpp"
//��һ������0��������ֻ��������ֻ����������������
void Function(LinkList &A,LinkList &B,LinkList &C){
    LinkList* p=A.Next;
    LinkList* Bp=&B;
    LinkList* Cp=&C;
    while (p)
    {
        if (p->data>0)
        {
            Bp->Next=p;
            Bp=Bp->Next;
        }
        else{
            Cp->Next=p;
            Cp=Cp->Next;
        }
        p=p->Next;
    }
    Bp->Next=Cp->Next=NULL;
}
int main(){
    LinkList A;//A,B,C���ǰ����ڱ��ڵ������
    LinkList B;
    LinkList C;
    A.Next=NULL;
    LinkList* CurPoint=&A;
    LinkList* CurPointB=&B;
    LinkList* CurPointC=&C;
    LinkListPushBack(&A,7);
    LinkListPushBack(&A,-1);
    LinkListPushBack(&A,3);
    LinkListPushBack(&A,3);
    LinkListPushBack(&A,-8);
    LinkListPushBack(&A,-1);
    LinkListPushBack(&A,-4);
    LinkListPushBack(&A,5);
    Function(*CurPoint,B,C);
    while (CurPointB->Next!=NULL)
    {
        printf("%d->",CurPointB->Next->data);
        CurPointB=CurPointB->Next;
    }
    printf("NULL\n");
    while (CurPointC->Next!=NULL)
    {
        printf("%d->",CurPointC->Next->data);
        CurPointC=CurPointC->Next;
    }
    printf("NULL\n");
}