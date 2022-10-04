//KMP�㷨ʵ���ַ�����ģʽƥ��
#include<iostream>
#include<cstring>
using namespace std;
//������A�в����Ӵ�B
//Next�����0��ʼ��Next[j]��ʾ��A[j+1]Ԫ����B[j+1]Ԫ�ز�ƥ��ʱ��Ҫ������Ԫ�ظ���
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
        cout<<"δ�ҵ�"<<endl;
        return -1;    
    }
    return i-j;   
}
int main(){
    cout<<"�Ӵ����±�Ϊ:"<<KMP("mississippi","issip")<<endl;
}