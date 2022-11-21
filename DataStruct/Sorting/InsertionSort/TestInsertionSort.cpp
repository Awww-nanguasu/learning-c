#include"D:\git-workspace\learning-c\DataStruct\Sorting\InsertionSort.cpp"
int main(){
    SeqList SL;
    SeqListInit(&SL);
    SeqListPushBack(&SL,-1);
    SeqListPushBack(&SL,3);
    SeqListPushBack(&SL,21);
    SeqListPushBack(&SL,-11);
    SeqListPushBack(&SL,-13);
    SeqListPushBack(&SL,10);
    SeqListPushBack(&SL,0);
    SeqListPushBack(&SL,1);
    SeqListDisplay(SL);
    InsertSorting(&SL);
    SeqListDisplay(SL);
}