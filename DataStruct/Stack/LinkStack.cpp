#include"LinkStack.h"
void InitStack(LinkStack &S){
    S=NULL;
}
void ClearStack(LinkStack &S){
    S=NULL;
}
bool StackEmpty(LinkStack S){
    return S==NULL;
}
int StackLength(LinkStack S){
    int Length=0;
    while (S)
    {
        S=S->Next;
    }
    return Length;
}
ElementType GetTop(LinkStack S){
    if (!S){
        return -1;
    }
    else{
        return S->data;
    }
}
void StackPush(LinkStack &S,ElementType Data){
    LinkStack Newnode=new Stack;
    Newnode->Next=S;
    Newnode->data=Data;
    S=Newnode;
}
void StackPop(LinkStack &S){
    S=S->Next;
}
void TraverlStack(LinkStack S){
    while (S)
    {
        cout<<S->data<<"->";
        S=S->Next;
    }
    cout<<"NULL"<<endl;
}