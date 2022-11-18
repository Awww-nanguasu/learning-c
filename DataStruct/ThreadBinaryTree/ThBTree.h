#pragma once
#include<iostream>
typedef char Elemtype;
using namespace std;
//规定：线索二叉树节点有五个域：lchild，ltag，data，rtag，rchild
//若节点有左孩子，则ltag为0，lchild指向左孩子，没有则ltag为1，lchild指向该节点前驱
//右边一致
//给线索二叉树添加一个头节点，令对应的二叉树最后一个节点的rchild和第一个节点的lchild指向1头节点
typedef struct ThBtree{
    Elemtype data;
    bool Rtag,Ltag;
    struct ThBtree* Lchild,*Rchild;
}ThBtree,*pThBtree;
pThBtree pre;
void InThreading(pThBtree &p);
void TravelThBtree(pThBtree p);
