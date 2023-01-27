
class Solution {
private:
    void printlst(Node *head){
        while(head){
            cout<<(head->val)<<" | ";
            head=head->next;
        }
        cout<<endl;
    }    
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node *temp=head;
        while(temp){
            Node *copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=copy->next;
        }
       
        temp=head;
        while(temp && temp->next){
            temp->next->random=temp->random ? temp->random->next : NULL;
            temp=temp->next->next;
        }

        temp=head;
        Node *copylst=NULL;
        Node *cur=NULL;
        while(temp){
            if(!copylst){
                copylst=temp->next;
                cur=copylst;
            }
            else{
                cur->next=temp->next;
                cur=cur->next;  
            }
            temp->next=cur->next;
            temp=temp->next;
        }
        return copylst;
    }
};