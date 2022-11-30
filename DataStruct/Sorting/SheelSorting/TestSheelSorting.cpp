#include"D:\git-workspace\learning-c\DataStruct\Sorting\SheelSorting\SheelSorting.cpp"
int main(){
    SeqList SL;int dt[3]={5,3,1};
    SeqListInit(&SL);
    SeqListPushBack(&SL,49);
    SeqListPushBack(&SL,38);
    SeqListPushBack(&SL,65);
    SeqListPushBack(&SL,97);
    SeqListPushBack(&SL,76);
    SeqListPushBack(&SL,13);
    SeqListPushBack(&SL,27);
    SeqListPushBack(&SL,49);
    SeqListPushBack(&SL,55);
    SeqListPushBack(&SL,4);
    SeqListDisplay(SL);
    SheelSorting(&SL,dt,3);
}