//力扣第19题，删除链表倒数第N个结点
/*    int k=0;
    if(head==NULL)
        return NULL;
    struct ListNode* SlowPoint=head;
    struct ListNode* FastPoint=head;
    while(FastPoint->next!=NULL){
        FastPoint=FastPoint->next;
        if(n<=0){
            SlowPoint=SlowPoint->next;
        }
        n--;
        k++;
    }
    if(k==0){
        return NULL;
    }
    else if(n>0)
        return SlowPoint->next;
    else{
        SlowPoint->next=SlowPoint->next->next;
        return head;
    }
}*/