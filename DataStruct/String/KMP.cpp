//KMP算法实现字符串的模式匹配
#include<iostream>
#include<cstring>
using namespace std;
//在主串A中查找子串B
//Next数组从0开始，Next[j]表示第A[j+1]元素与B[j+1]元素不匹配时需要跳过的元素个数
bool Compare(char a,char b){
    return a==b;
}
int KMP(string A,string B){
    int Next[B.size()],k=1,i=0,j=0;
    Next[0]=0;
    while (k<B.size())
    {
        int a=Next[k-1],b=k;
        while((!Compare(B[a],B[b]))&&a){
            a=Next[a-1];
        }
        if (Compare(B[a],B[b])){
            Next[k++]=a+1;   
        }
        else if (a==0)
        {
            Next[k++]=0;
        }
    }
    while (i<A.size() && j<B.size())
    {
        if (B[j]==A[i])
        {
            i++; j++;
        }
        else if (j==0)
        {
            i++;
        }
        else
        {
            j=Next[j-1];
        }
    }
    if (j!=B.size())
    {
        cout<<"未找到"<<endl;
        return -1;    
    }
    return i-j;   
}
int main(){
    cout<<"子串首下标为:"<<KMP("mississippi","issip")<<endl;
}