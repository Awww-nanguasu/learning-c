#include"Stack.h"
void CheckCapacity(Stack* SK){
    if (SK->Top==SK->Capacity)
    {
        SK->Capacity*=2;
        SK->Data=(StackData*)realloc(SK->Data,SK->Capacity);
    }
}
void StackInit(Stack* SK)
{
    SK->Top=0;
    SK->Capacity=4;
    SK->Data=(StackData*)malloc(sizeof(StackData)*4);
}
bool StackEmpty(Stack* SK){
    return SK->Top==0;
}
void StackPush(Stack* SK,StackData x){
    CheckCapacity(SK);
    SK->Data[SK->Top]=x;
    SK->Top++;
}
void StackPop(Stack* SK){
    if (!StackEmpty(SK))
    {
        SK->Top--;
    }
}
StackData StackTop(Stack* SK){
    if (StackEmpty(SK))
    {
        return NULL;
    }
    
    return SK->Data[SK->Top-1];
}
void StackDestory(Stack* SK){
    free(SK->Data);
    SK->Data=NULL;
}