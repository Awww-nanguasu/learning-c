#include"D:\git-workspace\learning-c\DataStruct\Map\Graph\AdjacencyMatrix\AMG.cpp"
void ShortestPath(AMG graph,VerTexType u){//顶点U到所有顶点的最短路径
    bool S[graph.vex];//一维数组，用于判断顶点是否被加入最优路径
    int Path[graph.vex];//用于记录前驱顶点序号
    int D[graph.vex];//用于记录权值
    int locate;//用于记录顶点的坐标序号
    for (int i = 0; i < graph.vex; i++){
        if (graph.vexs[i]==u){
            locate=i;
        }
    }    
   for (int i = 0; i < graph.vex; i++)
    {
        S[i]=false;D[i]=graph.arcs[locate][i];
        if (D[i]<MaxInt){Path[i]=locate;}//把与顶点相邻的点的前驱归为顶点
        else Path[i]=-1;//不相连的归为负一
    }
    S[locate]=true;D[locate]=0;//把顶点归入最短路径点，最短权值为1
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