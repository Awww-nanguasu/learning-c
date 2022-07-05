#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LinkListData;
typedef struct LinkList
{
    LinkListData data;
    LinkList* Next;
}LinkList;
LinkList* AddLinkListNode(LinkListData);
void LinkListPushFront(LinkList**,LinkListData);
void LinkListPushBack(LinkList*,LinkListData);
void LinkListPopFront(LinkList*);
void LinkListPopBack(LinkList*);
void LinkListErase(LinkList*,int pos);
void LinkListInsert(LinkList*,int pos,LinkListData);