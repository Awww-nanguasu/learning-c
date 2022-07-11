/*struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* PrePoint=NULL;
    struct ListNode* CurPoint=head;
    while(CurPoint){
        struct ListNode* Next=CurPoint->next;
        CurPoint->next=PrePoint;
        PrePoint=CurPoint;
        CurPoint=Next;
    }
    return PrePoint;
}*/