#include"D:\git-workspace\learning-c\DataStruct\Stack\LinkStack.cpp"
#include<cstring>
//�ж��Ƿ�Ϊ������
int main()
{
    Stack stack;
    LinkStack S=&stack;
    InitStack(S);
    int i;
    char s[20];
    gets(s);
    int Length=strlen(s);
    if(Length==1){cout<<"�ǻ���"<<endl;return 0;}
    for ( i = 0; i < Length/2; i++)
    {
        StackPush(S,s[i]);
    }
    if (Length%2!=0){i++;}
    while (s[i])
    {
        if (s[i]==S->data)
        {
            StackPop(S);
        }
        else{
            cout<<"�ǻ���"<<endl;
            return 0;
        }
        i++;
    }
    cout<<"����"<<endl;
}