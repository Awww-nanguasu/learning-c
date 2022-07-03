#include "SeqList.h"
void SeqListCheck(SeqList *SL){
    if (SL->size>=SL->capacity)
    {
        SL->capacity*=2;
        SL->a=(SeqListData*)realloc(SL->a,sizeof(SeqList)*(SL->capacity));
    }
}
void SeqListInit(SeqList *SL){
    SL->a=(SeqListData*)calloc(N,sizeof(SeqListData));
    SL->capacity=N;
    SL->size=0;
}
void SeqListPushFront(SeqList* SL,SeqListData data){
    int end=SL->size-1;
    SeqListCheck(SL);
    while (end>=0)
    {
        *(SL->a+end+1)=*(SL->a+end);
        end--;
    }
    SL->size++;
    *(SL->a)=data;
}
void SeqListPushBack(SeqList* SL,SeqListData data){
    SeqListCheck(SL);
    *(SL->a+SL->size)=data;
    SL->size++;
}
void SeqListPopBack(SeqList* SL){
    SL->size--;
}
void SeqListPopFront(SeqList*SL){
    int start=0;
    while (start<(SL->size-1))
    {
        *(SL->a+start)=*(SL->a+start+1);
        start++;
    }
    SL->size--;
}
void SeqListErase(SeqList*SL,int pos){
    if (pos<=0)
    {
        printf("请输入有效数字!\n");
    }
    else if(pos==1){
        SeqListPopFront(SL);
    }
    else if(pos>=SL->size)
    {
        SeqListPopBack(SL);
    }
    else 
    {
        int start=pos-1;
        while (start<(SL->size-1))
        {
            *(SL->a+start)=*(SL->a+start+1);
            start++;
        }
        SL->size--;
    }
}
void SeqListInsert(SeqList*SL,int pos,SeqListData data){
    if (pos<=0)
    {
        printf("请输入有效数字!\n");
    }
    else if(pos==1){
        SeqListPushFront(SL,data);
    }
    else if(pos>=SL->size)
    {
        SeqListPushBack(SL,data);
    }
    else{
        int end=SL->size-1;
        SeqListCheck(SL);
        while (end>=(pos-1))
        {
            *(SL->a+end+1)=*(SL->a+end);
            end--;
        }
        SL->size++;
        *(SL->a+pos-1)=data;
    }
}

