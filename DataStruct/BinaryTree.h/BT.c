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
    scanf("%c",&Input);
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
void Printf(BT* Tree1){
    if (Tree1->Data!=' ')
    {
        printf("%c ",Tree1->Data);
        Printf(Tree1->LeftLeef);
        Printf(Tree1->RightLeef);
    }
}
int main(){
    BT Tree1;
    Tree1.Data=' ';
    Tree1.LeftLeef==NULL;
    Tree1.RightLeef==NULL;
    CreatBT(&Tree1);
    Printf(&Tree1);
}