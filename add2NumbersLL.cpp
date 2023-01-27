class Solution {
public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum_adj=l1->val+l2->val;
        int carry=sum_adj/10;
        //cout<<endl<<"Carry :"<<carry<<endl;
        struct ListNode *head=new ListNode(sum_adj%10);
        struct ListNode *p=head;
        
            l1=l1->next;
            l2=l2->next;
            
        while(l1!=NULL && l2!=NULL){    
            sum_adj=l1->val+l2->val+carry;
            carry=sum_adj/10;
            p->next=new ListNode(sum_adj%10);
            p=p->next;
            l1=l1->next;
            l2=l2->next;
        }
    //if(l1!=NULL){
        while(l1!=NULL){
            sum_adj=l1->val+carry;
            carry=sum_adj/10;
            p->next=new ListNode(sum_adj%10);
            p=p->next;
        
            l1=l1->next;
        }
    //}
        //if(l2!=NULL){
        while(l2!=NULL){
            sum_adj=l2->val+carry;
            carry=sum_adj/10;
            p->next=new ListNode(sum_adj%10);
            p=p->next;
            l2=l2->next;
        }
    //}
        if(carry!=0){
            p->next=new ListNode(carry);
        }
    return head;
    }
};