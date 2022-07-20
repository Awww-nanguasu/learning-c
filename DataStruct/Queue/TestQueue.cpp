#include"Queue.cpp"
void TestQueueEmpty(Queue* QU){
    if (QueueEmpty(QU))
    {
        printf("队列为空\n");
    }
    else{
        printf("队列不为空\n");
    }
}
void TestQueuePush(Queue* QU){
    QueuePush(QU,1);
    QueuePush(QU,1);
    QueuePush(QU,1);
    QueuePush(QU,1);
    QueuePush(QU,2);
}
void TestQueuePop(Queue* QU){
    QueuePop(QU);
    QueuePop(QU);
}
int main(){
    Queue QU;
    InitQueue(&QU);
    TestQueueEmpty(&QU);
    TestQueuePush(&QU);
    TestQueuePop(&QU);
    TestQueueEmpty(&QU);
    while (QU.Head!=NULL)
    {
        printf("%d ",QU.Head->x);
        QU.Head=QU.Head->Next;
    }
    return 0;
}