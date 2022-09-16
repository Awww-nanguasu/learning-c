#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LinkListData;
typedef struct LinkList
{
    LinkListData data;//
    LinkList* Next;
}LinkList;
LinkList* AddLinkListNode(LinkListData);//新建链表节点
void LinkListPushFront(LinkList**,LinkListData);//链表的头插
void LinkListPushBack(LinkList*,LinkListData);//链表的尾插
void LinkListPopFront(LinkList*);
void LinkListPopBack(LinkList*);
void LinkListErase(LinkList*,int pos);
void LinkListInsert(LinkList*,int pos,LinkListData);