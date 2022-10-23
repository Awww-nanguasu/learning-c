#pragma once
#include<iostream>
using namespace std;
typedef char Elemtype;
typedef struct BT
{
    struct BT* LC;
    struct BT* RC;
    Elemtype data;
}BT,*BTree;
void InitBTree(BT &T);//构造空树
bool BTreeEmpty(BT T);//初始条件：树存在，若为空返回True，否则返回False
int BTreeDepth();//初始条件：树存在，返回树的深度。
Elemtype BTreeValue(BT T,BT E);//若E为Head指向树中的某个节点，则返回E指向的值
void CreatBTree(BTree &T);//按照先序遍历的方式创建树
void FrontTravelBTree(BTree T);//前序遍历树
void AfterTravelBTree(BTree T);//后序遍历树
void MiddleTravelBTree(BTree T);//中序遍历树
void CopyBTree(BT T,BT NewT);//复制树T到NewT
int BTreeDepth(BTree T);//返回树T的最大深度