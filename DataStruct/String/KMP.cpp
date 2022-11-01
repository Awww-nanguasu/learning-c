//KMP算法实现字符串的模式匹配
#include<iostream>
#include<cstring>
using namespace std;
//在主串A中查找子串B,k为B下标，i为A下标
void ShowNext(int* Next,int SizeB){
    int k=1;
    while (k<=SizeB){
        cout<<Next[k++];
    }
    cout<<endl;
}
bool Compare(char a,char b){
    return a==b;
}
int KMP3(string A,string B){
    //Next数组从1开始，Next[j]表示第A[j-1]元素与B[j-1]元素不匹配时需要跳过的元素个数
    //即数前k-1个的前缀后缀
    int k=3,Next[B.size()+1],i=0,j=1;
    Next[1]=0,Next[2]=1;
    while (k<=B.size())
    {
        int a=Next[k-1],b=k-2;
        while((!Compare(B[a-1],B[b]))&&a){
            a=Next[a];
        }
        if (Compare(B[a-1],B[b])){
            Next[k++]=a+1;   
        }
        else if (a==0){
            Next[k++]=1;
        }
    }
    for (int k = 3; k <= B.size()+1; k++)
    {
        if (B[Next[k]-1]==B[k-1])
        {
            Next[k]=Next[Next[k]];
        }
    }
    ShowNext(Next,B.size());
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
            j=Next[j];
        }
    }
    if (j!=B.size())
    {
        cout<<"未找到"<<endl;
        return -1;    
    }
    return i-j;
}
int KMP2(string A,string B){
    //Next数组从1开始，Next[j]表示第A[j-1]元素与B[j-1]元素不匹配时需要跳过的元素个数
    //即数前k-1个的前缀后缀
    int k=3,Next[B.size()+1],i=0,j=1;
    Next[1]=0;
    if(B.size()>=2){Next[2]=1;}
    while (k<=B.size())
    {
        int a=Next[k-1],b=k-2;
        while((a&&!Compare(B[a-1],B[b]))){
            a=Next[a];
        }
        Next[k++]=a+1;   
    }
    ShowNext(&Next[0],B.size());
    while (i<A.size() && j<=B.size())
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
            j=Next[j];
        }
    }
    if (j!=B.size())
    {
        cout<<"未找到"<<endl;
        return -1;    
    }
    return i-j;
}
//Next数组从0开始，Next[j]表示第A[j+1]元素与B[j+1]元素不匹配时需要跳过的元素个数
//即数前k个的前缀后缀
int KMP1(string A,string B){
    int Next[B.size()],k=1,i=0,j=0;//定义Next数组，大小为B的长度
    Next[0]=0;//根据定义，Next数组第一个必是0
    while (k<B.size())//此处的Next数组算法为Next
    {
        int a=Next[k-1],b=k;//根据数学归纳法，Next[k]可由Next[k-1]算出，此处a，b可看作双指针
        while((!Compare(B[a],B[b]))&&a){//如果a，b不匹配或者a指向首字符，就结束循环
            a=Next[a-1];//当a，b不匹配时，去查找有没有更短的前后缀
        }
        if (Compare(B[a],B[b])){
            Next[k++]=a+1;   
        }
        else if (a==0){
            Next[k++]=0;
        }
    }
    while (i<A.size() && j<B.size()){
        if (B[j]==A[i]){
            i++; j++;
        }
        else if (j==0){
            i++;
        }
        else{
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
    cout<<"子串首下标为:"<<KMP3("abc","abcaabbabcab")<<endl;
}