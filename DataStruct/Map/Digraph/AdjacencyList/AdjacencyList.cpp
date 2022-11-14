#include"AdjacencyList.h"
void CreatGraph(AJ &Graph){
    cout<<"请输入总顶点数:";cin>>Graph.vexnum;
    cout<<"请输入每个节点的数据(顺序默认为1,2,3……):";
    for (int i = 0; i < Graph.vexnum; i++)
    {
        cin>>Graph.vexnode[i].data;
    }
    cout<<"请构造边表:(默认顺序从1开始,无边关系请输入0)"<<endl;
    for (int i = 0; i < Graph.vexnum; i++)
    {
        cout<<"请输入第"<<i+1<<"个顶点的边表";
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