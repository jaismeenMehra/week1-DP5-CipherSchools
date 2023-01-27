class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode *slow,*fast;
         slow=fast=head;
         if(head==NULL)
             return NULL;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
};
