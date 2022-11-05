#include"MiniCostTree.cpp"
int main(){
    AMG graph;
    CreatWeb(graph);
    //ShowAMG(graph);
    MiniCostTree(graph,'a');
}
// 65536 6 1 5 65536 65536
// 6 65536 5 65536 3 65536
// 1 5 65536 5 6 4
// 5 65536 5 65536 65536 2
// 65536 3 6 65536 65536 6
// 65536 65536 4 2 6 65536