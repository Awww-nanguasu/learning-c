#include"D:\git-workspace\learning-c\DataStruct\Map\Graph\AdjacencyMatrix\Map.cpp"
//������ڽӾ��󷨴洢��ͼ��ʹ��
bool Vistied[MaxSize];
//�ӵ�i�����㿪ʼ����
void DeepFirstSearch(AMG graph,int i){
    if (!Vistied[i-1])
    {
         cout<<i;Vistied[i-1]=true;
        for (int j = 0; j < graph.vex; j++)
        {
            if (graph.arcs[i-1][j])
            {
                DeepFirstSearch(graph,j+1);
            } 
        }   
    }    
}
int main(){
    AMG graph;
    CreatGraph(graph);
    //ShowAMG(graph);
    DeepFirstSearch(graph,1);
}
// 0 0 0 0 0 0 1 0 1 0
// 0 0 1 0 0 0 1 0 0 0
// 0 0 0 1 0 0 0 1 0 0
// 0 0 0 0 1 0 0 0 1 0
// 0 0 0 0 0 1 0 0 0 1
// 1 1 0 0 0 0 0 0 0 0
// 0 0 1 0 0 0 0 0 0 1
// 1 0 0 1 0 0 0 0 1 0
// 0 0 0 0 1 0 1 0 0 1
// 1 0 0 0 0 1 0 0 0 0