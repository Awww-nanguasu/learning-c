#include"BT.cpp"
//-+a^^*b^^-c^^d^^/e^^f^^
int main(){
    BT T1,T2;
    InitBTree(T1);
    BTree pT1=&T1;
    BTree pT2=&T2;
    // if (BTreeEmpty(T1))
    // {
    //     cout<<"������Ϊ��"<<endl;
    // }
    cout<<"�밴�����������˳������"<<endl;
    cout<<"����(��)������Ӧλ����ո����"<<endl;
    CreatBTree(pT1);
    FrontTravelBTree(pT1);
    cout<<endl;
    MiddleTravelBTree(&T1);
    //cout<<endl;
    //AfterTravelBTree(&T1);
    //CopyBTree(pT1,pT2);
    //MiddleTravelBTree(&T2);
    //cout<<endl;
    //cout<<BTreeDepth(&T2);
}