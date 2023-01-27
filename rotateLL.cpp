class Solution {
private:
    int lenOfLinkedList(ListNode *head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* revList(ListNode* head){
        if(!head)
            return NULL;
        
        ListNode *nhead=head;
        ListNode *cur=head;
        head=head->next;
        while(head){
            cur->next=head;
            head=head->next;
            cur=cur->next;
        }
        cur->next=NULL;
        return nhead;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        if(k==0)
            return head;
        int len=lenOfLinkedList(head);
        int multiple=k/len;
        int remains=k%len;
        if(multiple%2!=0){
            head=revList(head);
        }
        if(remains==0)
            return head;
        int jumps=len-remains-1;
        ListNode *temp=head;
        while(jumps){
            temp=temp->next;
            jumps--;
        }
        ListNode *rest=temp->next;
        ListNode *newHead=rest;
        temp->next=NULL;
        while(rest->next){
            rest=rest->next;
        }
        rest->next=head;
        return newHead;
    }
};