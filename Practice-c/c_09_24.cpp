#include"D:\git-workspace\learning-c\DataStruct\Stack\LinkStack.cpp"
#include<cstring>
int main(){
    char s[20];
    gets(s);
    int Length=strlen(s),I=0,O=0;
    for (int k = 0; k <Length; k++)
    {
        if (I<O)
        {
            cout<<"�Ƿ�"<<endl;
            return 0;
        }
        else if (s[k]=='I')
        {
            I++;
        }
        else
            O++;
    }
    if (I!=O)
    {
        cout<<"�Ƿ�"<<endl;
    }
    else
        cout<<"�Ϸ�"<<endl;
    return 0;
}