#pragma once
#include<iostream>
typedef char Elemtype;
using namespace std;
//�涨�������������ڵ��������lchild��ltag��data��rtag��rchild
//���ڵ������ӣ���ltagΪ0��lchildָ�����ӣ�û����ltagΪ1��lchildָ��ýڵ�ǰ��
//�ұ�һ��
//���������������һ��ͷ�ڵ㣬���Ӧ�Ķ��������һ���ڵ��rchild�͵�һ���ڵ��lchildָ��1ͷ�ڵ�
typedef struct ThBtree{
    Elemtype data;
    bool Rtag,Ltag;
    struct ThBtree* Lchild,*Rchild;
}ThBtree,*pThBtree;
pThBtree pre;
void InThreading(pThBtree &p);
void TravelThBtree(pThBtree p);
