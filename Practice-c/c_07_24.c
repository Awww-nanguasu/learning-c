//魔术师手中有A、2、3……J、Q、K十三张黑桃扑克牌。在表演魔术前，魔术师已经将他们按照一定的顺序叠放好（有花色的
//一面朝下）。
//魔术表演过程为：一开始，魔术师数1，然后把最上面的那张牌翻过来，是黑桃A；
//然后将其放到桌面上；第二次,魔术师数1、2；将第一张牌放到这些牌的最下面，将第二张牌翻转过来，正好是黑桃2；
//第三次，魔术师数1、2、3；将第1、2张牌依次放到这些牌的最下面，将第三张牌翻过来正好是黑桃3；……
//直到将所有的牌都翻出来为止。
//问原来牌的顺序是如何的。
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
