#pragma once
#include<iostream>
using namespace std;
typedef char Elemtype;
typedef struct BT
{
    struct BT* LC;
    struct BT* RC;
    Elemtype data;
}BT;
void InitBTree(BT &T);//�������
bool BTreeEmpty(BT T);//��ʼ�����������ڣ���Ϊ�շ���True�����򷵻�False
int BTreeDepth();//��ʼ�����������ڣ�����������ȡ�
Elemtype BTreeValue(BT T,BT E);//��EΪHeadָ�����е�ĳ���ڵ㣬�򷵻�Eָ���ֵ
void CreatBTree(BT* T);//������������ķ�ʽ������
void FrontTravelBTree(BT* T);//������
void CopyBTree(BT T,BT NewT);//������T��NewT
int BTreeDepth(BT T);//������T��������