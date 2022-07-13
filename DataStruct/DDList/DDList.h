#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int DDListData;
typedef struct DDList
{
    DDList* PrvPoint;
    DDListData data;
    DDList* Next;
}DDList;
DDList* CreatNewNode(DDListData x);
void DDListInit(DDList* Head);
void DDListPushFront(DDList* Head,DDListData x);
void DDListPushBack(DDList* Head,DDListData x);
void DDListPopFront(DDList* Head);
void DDListPopBack(DDList* Head);
void DDListInsert(DDList* Head,DDListData x,int Pos);
void DDListErase(DDList* Head,int Pos);
