#include"BT.H"
void InitBTree(BT &T){
    T.data=0;
    T.LC=T.RC=NULL;
}
bool BTreeEmpty(BT T){
    return &T;
}
void CreatBTree(BT* T){
    char Input;
    cin>>Input;
    if (Input=='^')
    {
        T->LC=T->RC=NULL;
    }
    else{
        BT* NextL=new BT;
        BT* NextR=new BT;
        T->LC=NextL;
        T->RC=NextR;
        CreatBTree(NextL);
        CreatBTree(NextR);
    }
    T->data=Input;
}
// Elemtype BTreeValue(BT T,BT E){
//     ;
// }
void FrontTravelBTree(BT* T){
    if (T->data!='^'&&T)
    {
        cout<<T->data;
        FrontTravelBTree(T->LC);
        FrontTravelBTree(T->RC);
    }
}
void MiddleTravelBTree(BT* T){
    if (T->data!='^'&&T)
    {
        MiddleTravelBTree(T->LC);
        cout<<T->data;
        MiddleTravelBTree(T->RC);
    }
}
void AfterTravelBTree(BT* T){
    if (T->data!='^'&&T)
    {
        AfterTravelBTree(T->LC);
        AfterTravelBTree(T->RC);
        cout<<T->data;
    }
}
void CopyBTree(BT* T,BT* NewT){
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
int BTreeDepth(BT* T){
    if (!T)
    {
        return -2;
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