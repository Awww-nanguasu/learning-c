#include"LinkStack.cpp"
//具体函数参见LinkStack.cpp
int main()
{
    Stack stack;
    LinkStack S=&stack;
    InitStack(S);
    while (S)
    {
        cout<<S->data<<"->";
        S=S->Next;
    }
    cout<<"NULL"<<endl;
}