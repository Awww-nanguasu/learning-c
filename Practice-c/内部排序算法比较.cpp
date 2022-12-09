#include<iostream>
#include<time.h>
using namespace std;
#define N 4
typedef int SeqListData;
typedef struct SeqList
{
    int capacity;
    SeqListData* a;
    int size;
}SeqList;
void SeqListInit(SeqList &SL){
    SL.capacity=4;
    SL.a=(SeqListData*)calloc(SL.capacity,sizeof(SeqListData));
    SL.size=0;
}
void SeqListCheck(SeqList &SL){//�ж�˳����Ƿ���Ҫ����
    if (SL.size==SL.capacity)
    {
        SL.capacity*=2;
        SL.a=(SeqListData*)realloc(SL.a,sizeof(SeqList)*SL.capacity);
    }
}
void SeqListPushBack(SeqList &SL,SeqListData data){//β�巨����˳���
    SeqListCheck(SL);
    SL.size++;
    SL.a[SL.size-1]=data;
}
void SeqListShow(SeqList SL){
    for (int i = 0; i <SL.size; i++)
    {
        cout<<SL.a[i]<<' ';
    }
    cout<<endl;
}
void BubbleSorting(SeqList &SL){
    for (int i = 0; i < SL.size; i++)
    {
        for (int j =0; j <SL.size-i-1; j++)
        {
            if (SL.a[j+1]<SL.a[j])
            {
                SeqListData tmp=0;
                tmp=SL.a[j+1];
                SL.a[j+1]=SL.a[j];
                SL.a[j]=tmp;
            }
        }
    }
}
void SheelSorting(SeqList &SL,int* dt,int t){//ϣ������
    int k=0;
    for (int i = 0; i < t; i++){
        for (int j = dt[i]; j<SL.size; j++){
            if (SL.a[j]<SL.a[j-dt[i]]){
                SeqListData tmp=SL.a[j];
                for (k=j-dt[i]; k>=0&&tmp<SL.a[k]; k=k-dt[i]){
                    SL.a[k+dt[i]]=SL.a[k];
                }
                SL.a[k+dt[i]]=tmp;
            }
        }
    }
}
void InsertSorting(SeqList &SL){//ֱ�Ӳ�������
    SeqListData tmp=0;int j;
    for (int i = 1; i < (SL.size); i++)
    {
        if (SL.a[i]<SL.a[i-1])
        {
            tmp=SL.a[i];SL.a[i]=SL.a[i-1];
            for (j = i-2; j>=0&&tmp<SL.a[j]; j--)
            {
                SL.a[j+1]=SL.a[j];
            }
            SL.a[j+1]=tmp;
        }
    }
}
void QuickSorting(SeqList &SL,int STDLocate,int CurLocate){//���������㷨
    if (STDLocate>=CurLocate)
    {
        return ;
    }
    int high=CurLocate,low=STDLocate,STD=SL.a[STDLocate];
    while (low!=high)
    {
        while (SL.a[high]>=STD&&low<high){high--;}
        while (SL.a[low]<=STD&&low<high){low++;}
        if (low<high)
        {
            int tmp=SL.a[low];
            SL.a[low]=SL.a[high];
            SL.a[high]=tmp;
        }
    }
    SL.a[STDLocate]=SL.a[low];
    SL.a[low]=STD;
    QuickSorting(SL,STDLocate,low-1);
    QuickSorting(SL,low+1,CurLocate);
}
void Test(int n){
    int start=0,end=0;
    SeqList SL;SeqListInit(SL);
    SeqList SL1;SeqListInit(SL1);
    SeqList SL2;SeqListInit(SL2);
    SeqList SL3;SeqListInit(SL3);
    srand((unsigned int)time(NULL));
    cout<<"----------����"<<n<<"�������------------"<<endl;
    for (int i = 0; i < n; i++)
    {
        int random=rand();
        //cout<<random<<' ';
        SeqListPushBack(SL,random);
        SeqListPushBack(SL1,random);
        SeqListPushBack(SL2,random);
        SeqListPushBack(SL3,random);
    }
    if (n<=100)
    {
        SeqListShow(SL);
        cout<<"����������:"<<endl;
        BubbleSorting(SL);
        SeqListShow(SL);
        cout<<"����������:"<<endl;
        QuickSorting(SL1,0,SL1.size-1);
        SeqListShow(SL1);
        int dk[3]={5,3,1};
        cout<<"ϣ��������:(����ѡȡ5,3,1)"<<endl;
        SheelSorting(SL2,dk,3);
        SeqListShow(SL2);
        cout<<"ֱ�Ӳ���������Ϊ:"<<endl;
        InsertSorting(SL3);
        SeqListShow(SL3);    
    }
    else{
        start=clock();
        QuickSorting(SL,0,SL.size-1);
        end=clock();
        cout<<"\n���������ʱΪ:"<<double(end-start)/CLK_TCK<<"s"<<endl;
        start=clock();
        BubbleSorting(SL1);
        end=clock();
        cout<<"���������ʱΪ:"<<double(end-start)/CLK_TCK<<"s"<<endl;
        start=clock();
        int dk[3]={5,3,1};
        SheelSorting(SL2,dk,3);
        end=clock();
        cout<<"ϣ�������ʱΪ(����ѡȡ5,3,1):"<<double(end-start)/CLK_TCK<<"s"<<endl;
        start=clock();
        InsertSorting(SL3);
        end=clock();
        cout<<"ֱ�Ӳ��������ʱΪ:"<<double(end-start)/CLK_TCK<<"s"<<endl;
    }
}
int main(){
    Test(10);
    cout<<endl;
    cout<<"------------------�ָ���------------------------"<<endl;
    Test(100);
    cout<<endl;
    cout<<"------------------�ָ���------------------------"<<endl;
    Test(100000);
}