#include<iostream>
#include"D:\git-workspace\learning-c\DataStruct\Map\Graph\AdjacencyMatrix\AMG.cpp"
using namespace std;
typedef char VerTexType;//顶点，数据类型为char
typedef int ArcType;//权值
struct //辅助数组，用于记录顶点集U到V-U的最小权值边
{
    VerTexType adjvex;//最小权值所在顶点
    ArcType lowcost;//最小耗费权值
}closedge[MaxSize];
void MiniCostTree(AMG graph,VerTexType u){
    int locate=0,l=0,j=0;//最小权值对应的顶点
    for (int i = 0; i < graph.vex; i++)//先遍历到节点u
    {
        if (u==graph.vexs[i])
        {
            locate=i;//记录下节点u在顶点中的位置
        }
    }
    for (int i = 0; i < graph.vex; i++)
    {
        if(i!=locate){closedge[i]={u,graph.arcs[locate][i]};}//closedge初始化为u顶点对应的行邻接矩阵
    }
    closedge[locate]={u,0};
    for (int i = 1; i < graph.vex; i++)
    {
        int tmp=MaxInt;
        for (j = 0; j < graph.vex; j++)
        {
            if (closedge[j].lowcost&&closedge[j].lowcost<tmp)
            {
                tmp=closedge[j].lowcost;//找出closedge中最小的权值
                locate=j;
            }
        }
        char u0=closedge[locate].adjvex,v0;//记录下最小权值对应的前顶点
        for (int k = 0; k < graph.vex; k++)
        {
            if (graph.vexs[k]==u0)
            {
                for (l = 0; l < graph.vex; l++)
                {
                    if (graph.arcs[k][l]==closedge[locate].lowcost)
                    {
                        v0=graph.vexs[l];break;//记录下最小权值对应的下一个顶点
                    }
                }
                break;
            }   
        }
        cout<<'<'<<u0<<','<<v0<<'>'<<endl;
        closedge[locate].lowcost=0;
        for (int n = 0; n < graph.vex; n++)
        {
            if (graph.arcs[l][n]<closedge[n].lowcost)
            {
                closedge[n]={graph.vexs[l],graph.arcs[l][n]};//用最小权值后一个顶点对应的行邻接矩阵与closedge比较大小，记录下新的closedge
            }
        }
    }
}
