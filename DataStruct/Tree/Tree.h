//����˫�ױ�ʾ��
#define Tree_Max_Size 100 
typedef struct CTNode
{
    struct CTNode* Next;//ָ���¸����ӽڵ��ָ��
    int Child;//���ӽڵ���±�   
}CT;
typedef struct CTBox
{
    int Data;//���ڽڵ��е�����
    int Parent;//���˫���±�
    CTNode* Child;//ָ���һ�����ӵ�ָ��
}CTB;
struct Map
{
    CTBox Box[Tree_Max_Size];//��Ŷ��CTBox������
};