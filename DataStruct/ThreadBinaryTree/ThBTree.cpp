#include"ThBtree.h"
void CreatThBTree(pThBtree &T){
    char Input;
    cin>>Input;
    if (Input=='^')
    {
        T=NULL;
    }
    else{
        T->data=Input;
        T->Lchild=new ThBtree;
        T->Rchild=new ThBtree;
        CreatThBTree(T->Lchild);
        CreatThBTree(T->Rchild);
    }
}
void InThreading(pThBtree &p){
    if (p)
    {
        //cout<<"1";
        InThreading(p->Lchild);
        //cout<<"2"<<endl;
        if (p->Lchild==NULL)
        {
          //  cout<<"3"<<endl;
            p->Ltag=1;
            p->Lchild=pre;
        }
        else p->Ltag=0;
        //cout<<"2.5"<<endl;
        if (pre&&pre->Rchild==NULL)
        {
            //cout<<"3"<<endl;
            pre->Rtag=1;
            pre->Rchild=p;
        }
        else if(pre){pre->Rtag=0;}
        //cout<<"5"<<endl;
        pre=p;
        //cout<<"6"<<endl;
        InThreading(p->Rchild);
    }   
}
void FrontTravelThBTree(pThBtree T){
    if (T)
    {
        cout<<T->data;
        FrontTravelThBTree(T->Lchild);
        FrontTravelThBTree(T->Rchild);
    }
}
void MiddleTravelThBTree(pThBtree T){
    if (T)
    {
        MiddleTravelThBTree(T->Lchild);
        cout<<T->data;
        MiddleTravelThBTree(T->Rchild);
    }
}