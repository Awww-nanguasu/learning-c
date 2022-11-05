#include<iostream>
#include"D:\git-workspace\learning-c\DataStruct\Map\Graph\AdjacencyMatrix\AMG.cpp"
using namespace std;
typedef char VerTexType;//���㣬��������Ϊchar
typedef int ArcType;//Ȩֵ
struct //�������飬���ڼ�¼���㼯U��V-U����СȨֵ��
{
    VerTexType adjvex;//��СȨֵ���ڶ���
    ArcType lowcost;//��С�ķ�Ȩֵ
}closedge[MaxSize];
void MiniCostTree(AMG graph,VerTexType u){
    int locate=0,l=0,j=0;//��СȨֵ��Ӧ�Ķ���
    for (int i = 0; i < graph.vex; i++)//�ȱ������ڵ�u
    {
        if (u==graph.vexs[i])
        {
            locate=i;//��¼�½ڵ�u�ڶ����е�λ��
        }
    }
    for (int i = 0; i < graph.vex; i++)
    {
        if(i!=locate){closedge[i]={u,graph.arcs[locate][i]};}//closedge��ʼ��Ϊu�����Ӧ�����ڽӾ���
    }
    closedge[locate]={u,0};
    for (int i = 1; i < graph.vex; i++)
    {
        int tmp=MaxInt;
        for (j = 0; j < graph.vex; j++)
        {
            if (closedge[j].lowcost&&closedge[j].lowcost<tmp)
            {
                tmp=closedge[j].lowcost;//�ҳ�closedge����С��Ȩֵ
                locate=j;
            }
        }
        char u0=closedge[locate].adjvex,v0;//��¼����СȨֵ��Ӧ��ǰ����
        for (int k = 0; k < graph.vex; k++)
        {
            if (graph.vexs[k]==u0)
            {
                for (l = 0; l < graph.vex; l++)
                {
                    if (graph.arcs[k][l]==closedge[locate].lowcost)
                    {
                        v0=graph.vexs[l];break;//��¼����СȨֵ��Ӧ����һ������
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
                closedge[n]={graph.vexs[l],graph.arcs[l][n]};//����СȨֵ��һ�������Ӧ�����ڽӾ�����closedge�Ƚϴ�С����¼���µ�closedge
            }
        }
    }
}
