 #include"D:\git-workspace\learning-c\DataStruct\DDList\DDList.cpp"
//双向链表中，交换节点A和其前驱
void change(DDList &A){
    DDList* Ap=&A;
    DDList* q=Ap->PrvPoint;
    q->Next=Ap->Next;
    Ap->Next->PrvPoint=q;
    Ap->PrvPoint=q->PrvPoint;
    q->PrvPoint->Next=Ap;
    Ap->Next=q;
    q->PrvPoint=Ap;
}
int main(){
    DDList L;
    DDList* Lp=&L;
    DDListInit(Lp);
    DDListPushBack(Lp,1);
    DDListPushBack(Lp,2);
    DDListPushBack(Lp,3);
    DDListPushBack(Lp,4);
    DDListPushBack(Lp,5);
    DDListPushBack(Lp,6);
    DDListPushBack(Lp,7);
    for (int i = 0; i < 3; i++)
    {
        Lp=Lp->Next;
    }
    change(*Lp);
    Lp=&L;
    while (Lp->Next!=&L)
    {
        cout<<Lp->data<<"->";
        Lp=Lp->Next;
    }
    cout<<L.data<<endl;
}