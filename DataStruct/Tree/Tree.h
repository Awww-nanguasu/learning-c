//孩子双亲表示法
#define Tree_Max_Size 100 
typedef struct CTNode
{
    struct CTNode* Next;//指向下个孩子节点的指针
    int Child;//孩子节点的下标   
}CT;
typedef struct CTBox
{
    int Data;//存在节点中的数据
    int Parent;//存放双亲下标
    CTNode* Child;//指向第一个孩子的指针
}CTB;
struct Map
{
    CTBox Box[Tree_Max_Size];//存放多个CTBox的数组
};