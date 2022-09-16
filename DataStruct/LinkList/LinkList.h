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
LinkList* AddLinkListNode(LinkListData);//�½�����ڵ�
void LinkListPushFront(LinkList**,LinkListData);//�����ͷ��
void LinkListPushBack(LinkList*,LinkListData);//�����β��
void LinkListPopFront(LinkList*);
void LinkListPopBack(LinkList*);
void LinkListErase(LinkList*,int pos);
void LinkListInsert(LinkList*,int pos,LinkListData);