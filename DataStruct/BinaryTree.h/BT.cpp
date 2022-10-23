#include"BT.H"
void InitBTree(BT &T){
    T.data=0;
    T.LC=T.RC=NULL;
}
bool BTreeEmpty(BT T){
    return &T;
}
void CreatBTree(BTree &T){
    char Input;
    cin>>Input;
    if (Input=='^')
    {
        T=NULL;
    }
    else{
        T->data=Input;
        T->LC=new BT;
        T->RC=new BT;
        CreatBTree(T->LC);
        CreatBTree(T->RC);
    }
}
// Elemtype BTreeValue(BT T,BT E){
//     ;
// }
void FrontTravelBTree(BTree T){
    if (T)
    {
        cout<<T->data;
        FrontTravelBTree(T->LC);
        FrontTravelBTree(T->RC);
    }
}
void MiddleTravelBTree(BTree T){
    if (T)
    {
        MiddleTravelBTree(T->LC);
        cout<<T->data;
        MiddleTravelBTree(T->RC);
    }
}
void AfterTravelBTree(BTree T){
    if (T)
    {
        AfterTravelBTree(T->LC);
        AfterTravelBTree(T->RC);
        cout<<T->data;
    }
}
void CopyBTree(BTree T,BTree &NewT){
    if (T)
    {
        NewT->data=T->data;
        NewT->LC=new BT;
        NewT->RC=new BT;
        CopyBTree(T->LC,NewT->LC);
        CopyBTree(T->RC,NewT->RC);   
    }
    else{
        NewT=NULL;
    }
}
int BTreeDepth(BTree T){
    if (!T)
    {
        return 0;
    }
    else{
        int n=BTreeDepth(T->LC);
        int m=BTreeDepth(T->RC);
        if (n<m)
        {
            n=m;
        }
        return n+1;
    }
    
}