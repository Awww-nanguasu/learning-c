#include"ThBTree.cpp"
//ABC^DE^^^^^
int main(){
    ThBtree T;
    pThBtree pT=&T;
    cout<<"�밴�����������˳������"<<endl;
    cout<<"����(��)������Ӧλ����'^'����"<<endl;
    CreatThBTree(pT);
    //FrontTravelThBTree(pT);
    MiddleTravelThBTree(pT);
    InThreading(pT);
    cout<<endl;
    cout<<pT->Lchild->Lchild->Rchild->Lchild->Lchild->data<<endl;
}