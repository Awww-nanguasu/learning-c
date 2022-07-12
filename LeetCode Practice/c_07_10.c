/*struct ListNode* rotateRight(struct ListNode* head, int k){
    int Length=1;
    struct ListNode* CurPoint=head;
    if(CurPoint==NULL)
        return NULL;
    while(CurPoint->next!=NULL){
        CurPoint=CurPoint->next;
        Length++;
    }
    if(Length==1){
        return head;
    }
    k%=Length;
    int BreakPoint=Length-k;
    CurPoint->next=head;
    for(int i=0;i<BreakPoint;i++){
        CurPoint=CurPoint->next;
    }
    head=CurPoint->next;
    CurPoint->next=NULL;
    return head;
}*/