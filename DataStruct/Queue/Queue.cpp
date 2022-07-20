#include"Queue.h"
void InitQueue(Queue* QU){
    QU->Head=NULL;
}
bool QueueEmpty(Queue* QU){
    return QU->Head==NULL;
}
void QueuePush(Queue* QU,QueueData X){
    QNode* NewNode=(QNode*)malloc(sizeof(QNode));
    NewNode->x=X;
    NewNode->Next=NULL;
    if (QueueEmpty(QU))
    {
       QU->Head=QU->Tail=NewNode;
    }
    else{
        QU->Tail->Next=NewNode;
        QU->Tail=NewNode;
    }
}
void QueuePop(Queue* QU){
    if (!QueueEmpty(QU))
    {
        QU->Head=QU->Head->Next;
    }
}
void QueueDestroy(Queue* QU){
    ;
}