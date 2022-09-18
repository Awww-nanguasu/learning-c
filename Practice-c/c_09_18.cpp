#include"D:\git-workspace\learning-c\DataStruct\LinkList\LinkList.cpp"
//·´×ªÁ´±í
void Reserve(LinkList &A){
    LinkList* Cur=A.Next,*pre=NULL,*next;
    while (Cur)
    {
        next=Cur->Next;
        Cur->Next=pre;
        pre=Cur;
        Cur=next;
    }
}
int main(){
    LinkList A;
    A.Next=NULL;
    LinkList* Ap=&A;
    LinkListPushBack(Ap,1);
    LinkListPushBack(Ap,2);
    LinkListPushBack(Ap,3);
    LinkListPushBack(Ap,4);
    LinkListPushBack(Ap,5);
    LinkListPushBack(Ap,6);
    LinkListPushBack(Ap,7);
    while (Ap->Next)
    {
        Ap=Ap->Next;
    }
    LinkList* Tail=Ap;
    Ap=&A;
    Reserve(A);
    while (Tail)
    {
        cout<<Tail->data<<"->";
        Tail=Tail->Next;
    }
    cout<<"NULL"<<endl;
    
}