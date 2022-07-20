#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int QueueData;
typedef struct QueueNode
{
    QueueNode* Next;
    QueueData x;
}QNode;
typedef struct Queue
{
    QNode* Head;
    QNode* Tail;
}Queue;
void InitQueue();
void QueuePush();
void QueuePop();
void QueueDestroy();
void QueueTop();
bool QueueEmpty();