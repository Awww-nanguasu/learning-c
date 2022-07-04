#include"SeqList.cpp"
void TestInit(SeqList* SL){
    SeqListInit(SL);
}
void TestPushFront(SeqList* SL){
    SeqListPushFront(SL,1);
    SeqListPushFront(SL,2);
    SeqListPushFront(SL,3);
    SeqListPushFront(SL,4);
    SeqListPushFront(SL,5);
    SeqListPushFront(SL,6);
    SeqListPushFront(SL,7);
    SeqListPushFront(SL,8);
    SeqListPushFront(SL,9);
    SeqListPushFront(SL,10);
}
void TestPushBack(SeqList* SL){
    SeqListPushBack(SL,-1);
}
void TestPopBack(SeqList* SL){
    SeqListPopBack(SL);
}
void TestPopFront(SeqList* SL){
    SeqListPopFront(SL);
}
void TestErase(SeqList* SL,int pos){
    SeqListErase(SL,pos);
}
void TestInsert(SeqList* SL,int pos,SeqListData data){
    SeqListInsert(SL,pos,data);
}
int main(){
    SeqList SL;
    TestInit(&SL);//≥ı ºªØ≤‚ ‘
    TestPushFront(&SL);// ◊≤Â≤‚ ‘
    TestPushBack(&SL);//Œ≤≤Â≤‚ ‘
    TestPopBack(&SL);//Œ≤…æ≤‚ ‘
    TestPopFront(&SL);// ◊…æ≤‚ ‘
    TestErase(&SL,100);//…æ≥˝≤‚ ‘
    TestInsert(&SL,100,3);//≤Â»Î≤‚ ‘
    for (int i = 0; i < SL.size; i++)
    {
        printf("%d ",*(SL.a+i));
    }
    printf("\n size:%d capacity:%d",SL.size,SL.capacity);
}