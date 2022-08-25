#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct BinaryTree
{
    int Data;
    struct BinaryTree* LeftLeef,*RightLeef;
}BT;
void CreatBT(BT* Tree1){
    char Input;
    scanf("%c",&Input);//请一个个输入
    getchar();
    if (' '==Input)
    {
        Tree1->LeftLeef=Tree1->RightLeef=NULL;
    }
    else
    {
        Tree1->LeftLeef=(BT*)malloc(sizeof(BT));
        Tree1->RightLeef=(BT*)malloc(sizeof(BT));
        CreatBT(Tree1->LeftLeef);
        CreatBT(Tree1->RightLeef);
    }
    Tree1->Data=Input;
}
void Printf(BT* Tree1,int Level){
    if (Tree1->Data!=' ')
    {
        printf("第%d层:%c\n",Level,Tree1->Data);
        Printf(Tree1->LeftLeef,Level+1);
        Printf(Tree1->RightLeef,Level+1);
    }
}
int main(){
    BT Tree1;
    Tree1.Data=' ';
    Tree1.LeftLeef==NULL;
    Tree1.RightLeef==NULL;
    CreatBT(&Tree1);
    Printf(&Tree1,0);
}