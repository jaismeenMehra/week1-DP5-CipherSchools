class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                break;
        }
        cout<<slow->val;
        if(!fast || !fast->next)
            return NULL;
        slow=head;
        while(fast!=slow){
            cout<<"loop"<<endl;
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};