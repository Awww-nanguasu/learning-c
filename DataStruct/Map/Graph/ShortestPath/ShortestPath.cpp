#include"D:\git-workspace\learning-c\DataStruct\Map\Graph\AdjacencyMatrix\AMG.cpp"
void ShortestPath(AMG graph,VerTexType u){//����U�����ж�������·��
    bool S[graph.vex];//һά���飬�����ж϶����Ƿ񱻼�������·��
    int Path[graph.vex];//���ڼ�¼ǰ���������
    int D[graph.vex];//���ڼ�¼Ȩֵ
    int locate;//���ڼ�¼������������
    for (int i = 0; i < graph.vex; i++){
        if (graph.vexs[i]==u){
            locate=i;
        }
    }    
   for (int i = 0; i < graph.vex; i++)
    {
        S[i]=false;D[i]=graph.arcs[locate][i];
        if (D[i]<MaxInt){Path[i]=locate;}//���붥�����ڵĵ��ǰ����Ϊ����
        else Path[i]=-1;//�������Ĺ�Ϊ��һ
    }
    S[locate]=true;D[locate]=0;//�Ѷ���������·���㣬���ȨֵΪ1
    for (int i = 1; i < graph.vex; i++)
    {
        int tmp=MaxInt;
        for (int j = 0; j < graph.vex; j++)
        {
            if (D[j]&&D[j]<tmp)
            {
                ; 
            }
            
        }
        
    }
    
}