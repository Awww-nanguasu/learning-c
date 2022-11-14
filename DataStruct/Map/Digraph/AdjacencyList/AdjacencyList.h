//邻接表存储图
#include<iostream>
using namespace std;
typedef int Elementype;
#define MaxSize 100
typedef struct ArcNode//边节点
{
    int prevex;
    struct ArcNode* nextarc;    
}ArcNode;
typedef struct VexNode//顶点节点
{
    Elementype data;
    ArcNode* Arc;
}VNode;
typedef struct AdjList//邻接表
{
    VexNode vexnode[MaxSize];
    int vexnum;
}AJ;

void  CreatGraph();//用邻接表法创建图
