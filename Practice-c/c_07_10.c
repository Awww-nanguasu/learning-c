//���۵�83�⣬ɾ���������ظ�Ԫ�ء�
/*struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL){
        return NULL;
    }
    struct ListNode* CurPoint=head;
    while(CurPoint->next){
        if(CurPoint->val==CurPoint->next->val){
            CurPoint->next=CurPoint->next->next;
        }
        else{
            CurPoint=CurPoint->next;
        }
    }
    return head;
}*/