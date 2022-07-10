//力扣第83题，删除链表中重复元素。
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