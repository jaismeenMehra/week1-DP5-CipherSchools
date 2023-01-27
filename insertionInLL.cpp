class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1=0,count2=0;
    ListNode *p1=headA,*p2=headB;
        
        while(p1 || p2){
            if(p1){
            count1++;
            p1=p1->next;}
            else{
                count2++;
                p2=p2->next;
            }
        }
        
        int diff=abs(count1-count2);
        if(count1<count2){
            swap(headA,headB);
        }
        while(headA && diff!=0){
            headA=headA->next;
            diff--;
        }
        while(headA && headB && headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }

        if(!headA || !headB){
            return NULL;
        }
        return headA;
    }
};