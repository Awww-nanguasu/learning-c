#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int StackData;
typedef struct Stack
{
    StackData* Data;
    int Top;
    int Capacity;
}Stack;
void StackInit(Stack* SK);
void StackDestroy(Stack* SK);
void StackPush(Stack* SK,StackData x);
void StackPop(Stack* SK);
StackData StackTop(Stack* SK);
void StackSize(Stack* SK);
bool StackEmpty(Stack* SK);
void CheckCapcacity(Stack* SK);
