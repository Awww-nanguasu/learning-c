#include"AMG.h"
void InitAM(AMG &Graph){
    for (int i = 0; i < Graph.vex; i++)
    {
        cout<<"请输入第"<<i+1<<"个顶点的值:";
        cin>>Graph.vexs[i];
        for (int k = 0; k < Graph.vex; k++)
        {
            Graph.arcs[i][k]=0;
        }
    }
}
void CreatGraph(AMG &Graph){
    cout<<"开始创建不带权值的无向图"<<endl;
    cout<<"请输入总顶点数:";cin>>Graph.vex;
    InitAM(Graph);//初始化邻接矩阵
    for (int i = 0; i < Graph.vex; i++)
    {
        cout<<"请输入第"<<i+1<<"行数据";
        for (int k = 0; k < Graph.vex; k++)
        {
            cin>>Graph.arcs[i][k];
        }
    }
}
void CreatWeb(AMG &Graph){//创建网
    cout<<"开始创建网"<<endl;
    cout<<"请输入总顶点数";cin>>Graph.vex;
    InitAM(Graph);
    for (int i = 0; i < Graph.vex; i++)
    {
        cout<<"请输入第"<<i+1<<"行数据(无穷权值用65536替代)";
        for (int k = 0; k < Graph.vex; k++)
        {
            cin>>Graph.arcs[i][k];
        }
    }
}
void ShowAMG(AMG &Graph){
    for (int i = 0; i < Graph.vex; i++)
    {
        cout<<Graph.vexs[i]<<": ";
        for (int k = 0; k < Graph.vex; k++)
        {
            cout<<Graph.arcs[i][k]<<' ';
        }
        cout<<endl;
    }    
}