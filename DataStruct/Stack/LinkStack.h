#include<iostream>
//链栈的实现
//结构：一个节点:数据域和指针域
//方法:头插法，保证头指针为栈顶
using namespace std;
typedef char ElementType;
typedef struct Stack{
    ElementType data;
    struct Stack* Next;
    
}Stack,*LinkStack;//这里的LinkList==Stack*
void InitStack(LinkStack &S);
void ClearStack(LinkStack &S);
bool StackEmpty(LinkStack S);
int StackLength(LinkStack S);
ElementType GetTop(LinkStack S);
void StackPush(LinkStack &S,ElementType Data);
void StackPop(LinkStack &S);
void TraverlStack(LinkStack S);