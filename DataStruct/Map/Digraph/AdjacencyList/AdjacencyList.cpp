#include"AdjacencyList.h"
void CreatGraph(AJ &Graph){
    cout<<"�������ܶ�����:";cin>>Graph.vexnum;
    cout<<"������ÿ���ڵ������(˳��Ĭ��Ϊ1,2,3����):";
    for (int i = 0; i < Graph.vexnum; i++)
    {
        cin>>Graph.vexnode[i].data;
    }
    cout<<"�빹��߱�:(Ĭ��˳���1��ʼ,�ޱ߹�ϵ������0)"<<endl;
    for (int i = 0; i < Graph.vexnum; i++)
    {
        cout<<"�������"<<i+1<<"������ı߱�";
        ArcNode* &CurNode=Graph.vexnode[i].Arc=NULL;        
        while (1)
        {
            int Input;
            cin>>Input;
            if (Input==0){break;}
            ArcNode* NewNode=new ArcNode;
            NewNode->nextarc=CurNode;
            NewNode->prevex=Input;
            CurNode=NewNode;
        }
        // cout<<endl;
        // cout<<CurNode<<' ';
        // cout<<Graph.vexnode[i].Arc;
    }
}
void Show(AJ &Graph){
    for (int i = 0; i < Graph.vexnum; i++)
    {
        cout<<i+1<<"->";
        ArcNode* Curnode=Graph.vexnode[i].Arc;
        while (Curnode)
        {
            cout<<Curnode->prevex<<"->";
            Curnode=Curnode->nextarc;
        }
        cout<<"NULL"<<endl;
    }
    
}