#pragma once
#include<stdio.h>
#include<stdlib.h>
#define N 4
typedef int SeqListData;
typedef struct SeqList
{
    int capacity;
    SeqListData* a;
    int size;
}SeqList;
void SeqListInit(SeqList*);
void SeqListPushBack(SeqList*,SeqListData );
void SeqListPushFront(SeqList*,SeqListData );
void SeqListPopBack(SeqList*);
void SeqListPopFront(SeqList*);
void SeqListErase(SeqList*,int);
void SeqListInsert(SeqList*,SeqListData ,int );
void SeqListCheck(SeqList*);
