#include"ThBTree.cpp"
//ABC^DE^^^^^
int main(){
    ThBtree T;
    pThBtree pT=&T;
    cout<<"请按照先序遍历的顺序输入"<<endl;
    cout<<"无右(左)孩子相应位置请'^'代替"<<endl;
    CreatThBTree(pT);
    //FrontTravelThBTree(pT);
    MiddleTravelThBTree(pT);
    InThreading(pT);
    cout<<endl;
    cout<<pT->Lchild->Lchild->Rchild->Lchild->Lchild->data<<endl;
}