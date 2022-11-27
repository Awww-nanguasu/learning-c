#include"D:\git-workspace\learning-c\DataStruct\Sorting\SimpleSelectionSort\SimpleSelectionSort.cpp"
/*int main(){
    SeqList SL;
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
    SimpleSelectionSort(&SL);
    SeqListDisplay(SL);
}*/
int main(){
    LinkList LL;
    LinkListInit(&LL);
    LinkListPushBack(&LL,49);
    LinkListPushBack(&LL,38);
    LinkListPushBack(&LL,65);
    LinkListPushBack(&LL,97);
    LinkListPushBack(&LL,76);
    LinkListPushBack(&LL,13);
    LinkListPushBack(&LL,27);
    LinkListPushBack(&LL,49);
    LinkListPushBack(&LL,55);
    LinkListPushBack(&LL,4);
    LinkListDisplay(LL);
    SimpleSelectionSort(&LL);
    LinkListDisplay(LL);
}