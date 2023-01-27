class Comparator{
public:
    bool operator()(ListNode *node1,ListNode *node2){
        return node1->val>node2->val;
    }
}nc;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=NULL;
        ListNode *temp=NULL;

        priority_queue<ListNode*,vector<ListNode*>,decltype(nc)> pq;
        for(ListNode *list:lists){
            if(list){
                pq.push(list);
            }
        }
        while(!pq.empty()){
            ListNode *lst=pq.top();
            pq.pop();
            if(!head){
                head=lst;
                lst=lst->next;
                if(lst){
                    pq.push(lst);
                }
                head->next=nullptr;
                temp=head;
            }else{
                temp->next=lst;
                temp=temp->next;
                lst=lst->next;
                if(lst){
                    pq.push(lst);
                }
            }
        }

        return head;  
    }
};