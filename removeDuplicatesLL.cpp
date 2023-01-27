class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        
        ListNode *prev=NULL;
        ListNode *hd=head;
        while(head){
            if(prev && head->val==prev->val){
                ListNode *tmp=head->next;
                prev->next=tmp;
                delete head;
                head=tmp;
                continue;
            }
            prev=head;
            head=head->next;
        }
        return hd;
    }
};