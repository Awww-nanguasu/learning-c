//ħ��ʦ������A��2��3����J��Q��Kʮ���ź����˿��ơ��ڱ���ħ��ǰ��ħ��ʦ�Ѿ������ǰ���һ����˳����źã��л�ɫ��
//һ�泯�£���
//ħ�����ݹ���Ϊ��һ��ʼ��ħ��ʦ��1��Ȼ���������������Ʒ��������Ǻ���A��
//Ȼ����ŵ������ϣ��ڶ���,ħ��ʦ��1��2������һ���Ʒŵ���Щ�Ƶ������棬���ڶ����Ʒ�ת�����������Ǻ���2��
//�����Σ�ħ��ʦ��1��2��3������1��2�������ηŵ���Щ�Ƶ������棬���������Ʒ����������Ǻ���3������
//ֱ�������е��ƶ�������Ϊֹ��
//��ԭ���Ƶ�˳������εġ�
#include<stdio.h>
#include<stdlib.h>
typedef struct Card
{
    int x;
    struct Card* Next;
}Card;
void CreatNode(Card* Cursor){
    Card* Newnode=(Card*)malloc(sizeof(Card));
    Cursor->Next=Newnode;
    Newnode->x=0;
    Newnode->Next=NULL;
}
int main(){
    int k=0,Count=0,j=1;
    Card Cards;
    Cards.x=0;
    Cards.Next=NULL;
    Card* Cursor=&Cards;
    for (int i = 0; i < 12; i++)
    {
        CreatNode(Cursor);
        Cursor=Cursor->Next;
    }
    Cursor->Next=&Cards;
    Cursor=&Cards;
    while (Count!=12)
    {
        Cursor->x=j;
        j++;
        Count++;
        for (int k = 1; k <= j; k++)
        {
            Cursor=Cursor->Next;
            if (Cursor->x!=0)
            {
                k--;
            }
        }
    }
    printf(" 1 ");
    Cursor=(&Cards)->Next;
    while ((Cursor)!=(&Cards))
    {
        printf("%d ",Cursor->x);
        Cursor=Cursor->Next;
    }
}
//1 2 3 4 5 6 7 8 9 10 11 12 13
//1 0 2 0 0 3 0 0 0 4  0  0   0
//1     
