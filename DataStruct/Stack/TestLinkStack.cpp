#include"LinkStack.cpp"
//���庯���μ�LinkStack.cpp
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