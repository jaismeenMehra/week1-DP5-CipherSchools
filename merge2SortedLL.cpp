class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *l1=list1;
        ListNode *l2=list2;
        ListNode *head=NULL;
        ListNode *temp=NULL;
        if(l1==NULL)
            return list2;
        if(l2==NULL)
            return list1;
        
        if(l1->val>l2->val)
            swap(l1,l2);
        head=l1;
        temp=head;
        l1=l1->next;
        head->next=NULL;
        
        while(l1 && l2){
            if(l1->val<l2->val)
            {
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
                temp->next=NULL;
                
            }
            else if(l1->val>l2->val)
            {
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
                temp->next=NULL;
            }
            else{
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
                temp->next=NULL;
                
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
                temp->next=NULL;
            }
        }
        while(l1){
            temp->next=l1;
            l1=l1->next;
            temp=temp->next;
            temp->next=NULL;
        }
        while(l2){
            temp->next=l2;
            l2=l2->next;
            temp=temp->next;
            temp->next=NULL;
        }
        return head;
    }
};