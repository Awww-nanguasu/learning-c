#include"LinkList.cpp"
void TestLinkListPushFront(LinkList** CurPoint){
    LinkListPushFront(CurPoint,0);
    LinkListPushFront(CurPoint,-1);
    LinkListPushFront(CurPoint,-2);;
}
void TestLinkListPushBack(LinkList* Curpoint){
    LinkListPushBack(Curpoint,2);
    LinkListPushBack(Curpoint,3);
    LinkListPushBack(Curpoint,4);
    LinkListPushBack(Curpoint,5);
}
void TestLinkListPopFront(LinkList** CurPoint){
    LinkListPopFront(CurPoint);
}
void TestLinkListPopBack(LinkList* CurPoint){
    LinkListPopBack(CurPoint);
}
void TestLinkListInsert(LinkList* CurPoint){
    LinkListInsert(CurPoint,100,3);
}

void TestLinkListErase(LinkList* CurPoint){
    LinkListErase(CurPoint,4);
}
int main(){
    LinkList LL;
    LL.data=1;
    LL.Next=NULL;
    LinkList* CurPoint=&LL;//将指针初始化为头指针
    TestLinkListPushFront(&CurPoint);
    TestLinkListPushBack(CurPoint);
    TestLinkListPopFront(&CurPoint);
    TestLinkListPopBack(CurPoint);
    TestLinkListInsert(CurPoint);
    TestLinkListErase(CurPoint);
    while (CurPoint!=NULL)
    {
        printf("%d->",CurPoint->data);
        CurPoint=CurPoint->Next;
    }
    printf("NULL\n");
}