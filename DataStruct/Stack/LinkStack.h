#include<iostream>
//��ջ��ʵ��
//�ṹ��һ���ڵ�:�������ָ����
//����:ͷ�巨����֤ͷָ��Ϊջ��
using namespace std;
typedef char ElementType;
typedef struct Stack{
    ElementType data;
    struct Stack* Next;
    
}Stack,*LinkStack;//�����LinkList==Stack*
void InitStack(LinkStack &S);
void ClearStack(LinkStack &S);
bool StackEmpty(LinkStack S);
int StackLength(LinkStack S);
ElementType GetTop(LinkStack S);
void StackPush(LinkStack &S,ElementType Data);
void StackPop(LinkStack &S);
void TraverlStack(LinkStack S);