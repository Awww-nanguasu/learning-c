//�ڽӱ�洢ͼ
#include<iostream>
using namespace std;
typedef int Elementype;
#define MaxSize 100
typedef struct ArcNode//�߽ڵ�
{
    int prevex;
    struct ArcNode* nextarc;    
}ArcNode;
typedef struct VexNode//����ڵ�
{
    Elementype data;
    ArcNode* Arc;
}VNode;
typedef struct AdjList//�ڽӱ�
{
    VexNode vexnode[MaxSize];
    int vexnum;
}AJ;

void  CreatGraph();//���ڽӱ�����ͼ
