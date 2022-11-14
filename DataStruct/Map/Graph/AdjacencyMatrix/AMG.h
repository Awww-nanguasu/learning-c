#include<iostream>
using namespace std;
#define MaxSize 100//最多顶点数
#define MaxInt 65536//定义极大值
typedef char VerTexType;
typedef int ArcType;
typedef struct AMGraph{
    VerTexType vexs[MaxSize];//顶点表
    ArcType arcs[MaxSize][MaxSize];//邻接矩阵
    int vex;
}AMG;
//初始化邻接矩阵，顶点默认编号为1，2，3……
void InitAM(AMG &Graph);
//使用邻接矩阵法创建无向图
void CreatGraph(AMG &Graph);
void ShowAMG(AMG &Graph);