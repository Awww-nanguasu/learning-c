#include"D:\git-workspace\learning-c\DataStruct\Map\Graph\AdjacencyMatrix\Map.cpp"
//深度在邻接矩阵法存储的图中使用
bool Vistied[MaxSize];
//从第i个顶点开始搜索
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