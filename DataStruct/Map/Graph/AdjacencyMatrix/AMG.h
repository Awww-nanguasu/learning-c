#include<iostream>
using namespace std;
#define MaxSize 100//��ඥ����
#define MaxInt 65536//���弫��ֵ
typedef char VerTexType;
typedef int ArcType;
typedef struct AMGraph{
    VerTexType vexs[MaxSize];//�����
    ArcType arcs[MaxSize][MaxSize];//�ڽӾ���
    int vex;
}AMG;
//��ʼ���ڽӾ��󣬶���Ĭ�ϱ��Ϊ1��2��3����
void InitAM(AMG &Graph);
//ʹ���ڽӾ��󷨴�������ͼ
void CreatGraph(AMG &Graph);
void ShowAMG(AMG &Graph);