//KMP�㷨ʵ���ַ�����ģʽƥ��
#include<iostream>
#include<cstring>
using namespace std;
//������A�в����Ӵ�B,kΪB�±꣬iΪA�±�
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
    //Next�����1��ʼ��Next[j]��ʾ��A[j-1]Ԫ����B[j-1]Ԫ�ز�ƥ��ʱ��Ҫ������Ԫ�ظ���
    //����ǰk-1����ǰ׺��׺
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
        cout<<"δ�ҵ�"<<endl;
        return -1;    
    }
    return i-j;
}
int KMP2(string A,string B){
    //Next�����1��ʼ��Next[j]��ʾ��A[j-1]Ԫ����B[j-1]Ԫ�ز�ƥ��ʱ��Ҫ������Ԫ�ظ���
    //����ǰk-1����ǰ׺��׺
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
        cout<<"δ�ҵ�"<<endl;
        return -1;    
    }
    return i-j;
}
//Next�����0��ʼ��Next[j]��ʾ��A[j+1]Ԫ����B[j+1]Ԫ�ز�ƥ��ʱ��Ҫ������Ԫ�ظ���
//����ǰk����ǰ׺��׺
int KMP1(string A,string B){
    int Next[B.size()],k=1,i=0,j=0;//����Next���飬��СΪB�ĳ���
    Next[0]=0;//���ݶ��壬Next�����һ������0
    while (k<B.size())//�˴���Next�����㷨ΪNext
    {
        int a=Next[k-1],b=k;//������ѧ���ɷ���Next[k]����Next[k-1]������˴�a��b�ɿ���˫ָ��
        while((!Compare(B[a],B[b]))&&a){//���a��b��ƥ�����aָ�����ַ����ͽ���ѭ��
            a=Next[a-1];//��a��b��ƥ��ʱ��ȥ������û�и��̵�ǰ��׺
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
        cout<<"δ�ҵ�"<<endl;
        return -1;    
    }
    return i-j;
}
int main(){
    cout<<"�Ӵ����±�Ϊ:"<<KMP3("abc","abcaabbabcab")<<endl;
}