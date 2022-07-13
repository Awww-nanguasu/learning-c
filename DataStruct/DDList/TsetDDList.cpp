#include"DDList.cpp"
void TestDDListInit(DDList* Head)
{
    DDListInit(Head);
}
void TestDDListPushFront(DDList* Head){
    DDListPushFront(Head,1);
    DDListPushFront(Head,4);
}
void TestDDListPushBack(DDList* Head){
    DDListPushBack(Head,2);
    DDListPushBack(Head,3);
}
void TestDDListPopFront(DDList* Head){
    DDListPopFront(Head);
    DDListPopFront(Head);
    DDListPopFront(Head);
}
void TestDDListPopBack(DDList* Head){
    DDListPopBack(Head);
}
void TestDDListInsert(DDList* Head){
    DDListInsert(Head,4,1); 
    DDListInsert(Head,3,2); 
    DDListInsert(Head,2,3); 
    DDListInsert(Head,100,100); 
    DDListInsert(Head,2,-100); 
}
void TestDDListErase(DDList* Head){
    DDListErase(Head,3);
    DDListErase(Head,1);
    DDListErase(Head,4);
    DDListErase(Head,0);
}
int main(){
    DDList Head;
    DDList* CurPoint=&Head;
    TestDDListInit(&Head);
    TestDDListPushFront(&Head);
    TestDDListPushBack(&Head);
    TestDDListPopFront(&Head);
    TestDDListPopBack(&Head);
    TestDDListInsert(&Head);
    TestDDListErase(&Head);
    printf("head->");
    while (CurPoint->Next != &Head)
    {
        CurPoint=CurPoint->Next;
        printf("%d->",CurPoint->data);
    }
    printf("head");
}