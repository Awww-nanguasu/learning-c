#include"AMG.h"
void InitAM(AMG &Graph){
    for (int i = 0; i < Graph.vex; i++)
    {
        cout<<"�������"<<i+1<<"�������ֵ:";
        cin>>Graph.vexs[i];
        for (int k = 0; k < Graph.vex; k++)
        {
            Graph.arcs[i][k]=0;
        }
    }
}
void CreatGraph(AMG &Graph){
    cout<<"��ʼ��������Ȩֵ������ͼ"<<endl;
    cout<<"�������ܶ�����:";cin>>Graph.vex;
    InitAM(Graph);//��ʼ���ڽӾ���
    for (int i = 0; i < Graph.vex; i++)
    {
        cout<<"�������"<<i+1<<"������";
        for (int k = 0; k < Graph.vex; k++)
        {
            cin>>Graph.arcs[i][k];
        }
    }
}
void CreatWeb(AMG &Graph){//������
    cout<<"��ʼ������"<<endl;
    cout<<"�������ܶ�����";cin>>Graph.vex;
    InitAM(Graph);
    for (int i = 0; i < Graph.vex; i++)
    {
        cout<<"�������"<<i+1<<"������(����Ȩֵ��65536���)";
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