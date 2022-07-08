//力扣第21题，合并两个有序链表
/*struct ListNode* compare(struct ListNode* list1,struct ListNode* list2){
    if(list1==NULL)
        return list2;
    else if(list2==NULL)
        return list1;
    if(list1->val>list2->val){
        list2->next=compare(list1,list2->next);
        return list2;
    }
    else
        list1->next=compare(list1->next,list2);
        return list1;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1==NULL)
        return list2;
    else if(list2==NULL)
        return list1;
    return compare(list1,list2);
}*/