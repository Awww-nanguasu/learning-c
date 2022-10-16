#include<iostream>
#define M 11
#define N 10
using namespace std;
void Function(int (*a)[10]){
    for (int i=0,j= 0; i < M;j++)
    {
        i+=(j/N);
        j%=N;
        for (int k=i+j/(N-1),l=(j+1)%N;k<M;k+=(l/N))
        {
            l%=N;
            if (a[i][j]==a[k][l])
            {
                cout<<"yes"<<endl;
            }
            l++;
        }
    }
}
int main(){
    int a[M][N]={0};
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            static int k=0;
            a[i][j]=k++;
        }
    }   
    Function(a);
}