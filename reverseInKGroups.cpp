class Solution {
private:
    int linkedListLength(ListNode *head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
            return head;
        
        int len=linkedListLength(head);
        int times=len/k;
        ListNode *f=NULL;
        ListNode *p=NULL;
        
        ListNode *newHead=NULL;
        while(head && times>0){
            int kk=1;
            times--;
            ListNode *nList=NULL;
            while(kk<=k && head){
                ListNode *temp=head;
                head=head->next;
                temp->next=nList;
                nList=temp;
                if(kk==1){
                    p=temp;
                }else if(kk==k){
                    if(f){
                        f->next=nList;
                    }else{
                        newHead=nList;
                    }
                    f=p;
                    p=NULL;
                    
                }
                kk++;

            }
          if(times==0)
              f->next=head;
        }
        return newHead;
    }

};