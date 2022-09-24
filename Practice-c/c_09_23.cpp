#include"D:\git-workspace\learning-c\DataStruct\Stack\LinkStack.cpp"
#include<cstring>
//判断是否为回文数
int main()
{
    Stack stack;
    LinkStack S=&stack;
    InitStack(S);
    int i;
    char s[20];
    gets(s);
    int Length=strlen(s);
    if(Length==1){cout<<"是回文"<<endl;return 0;}
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
            cout<<"非回文"<<endl;
            return 0;
        }
        i++;
    }
    cout<<"回文"<<endl;
}