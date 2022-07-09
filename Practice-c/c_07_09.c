//力扣第2题，两个逆序链表相加
//代码较冗长，可优化
/*struct ListNode* CreatNewNode(int n){
    struct ListNode* NewNode=(struct ListNode*)malloc(sizeof(struct ListNode));
    NewNode->val=n;
    NewNode->next=NULL;
    return NewNode;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* NewNode=CreatNewNode(0);
    struct ListNode* record=NewNode;
    while(l1||l2)
    {
        if(l1&&l2)
        {
            NewNode->val+=l1->val+l2->val;
            l1=l1->next;
            l2=l2->next;
            if(NewNode->val>9)
            {
                NewNode->next=CreatNewNode(1);
                NewNode->val%=10;
                NewNode=NewNode->next;
            }
            else if(l1||l2)
            {
                NewNode->next=CreatNewNode(0);
                NewNode=NewNode->next;
            }
        }
        else if(l1||l2)
        {
            if(l1==NULL)
            {
                NewNode->val+=l2->val;
                l2=l2->next;
                if(NewNode->val>9)
                {
                    NewNode->next=CreatNewNode(1);
                    NewNode->val%=10;
                    NewNode=NewNode->next;
                }
                else if(l2)
                {
                    NewNode->next=CreatNewNode(0);
                    NewNode=NewNode->next;
                }
            }
            else if(l2==NULL)
            {
                NewNode->val+=l1->val;
                l1=l1->next;
                if(NewNode->val>9)
                {
                    NewNode->next=CreatNewNode(1);
                    NewNode->val%=10;
                    NewNode=NewNode->next;
                }
                else if(l1)
                {
                    NewNode->next=CreatNewNode(0);
                    NewNode=NewNode->next;
                }
            }
        }
    }
    return record;
}*/