#include"BT.cpp"
int main(){
    BT T1,T2;
    InitBTree(T1);
    // if (BTreeEmpty(T1))
    // {
    //     cout<<"������Ϊ��"<<endl;
    // }
    cout<<"�밴�����������˳������"<<endl;
    cout<<"����(��)������Ӧλ����ո����"<<endl;
    CreatBTree(&T1);
    //FrontTravelBTree(&T1);
    //cout<<endl;
    MiddleTravelBTree(&T1);
    cout<<endl;
    //AfterTravelBTree(&T1);
    CopyBTree(&T1,&T2);
    MiddleTravelBTree(&T2);
    cout<<endl;
    cout<<BTreeDepth(&T2);
}