/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void copyinbw(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* nextele= temp->next;
            Node* copy= new Node(temp->val);

            copy->next= nextele;
            temp->next= copy;
            temp = nextele;
        }

    }
    void connectrp(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copynode= temp->next;
            if(temp->random){
                copynode->random = temp->random->next;
            } else{
                copynode->random=nullptr;
            }
            temp= temp->next->next;
        }
    }
    Node* getDCL(Node* head){
        Node* temp=head;
        Node* dummy = new Node(-1);
        Node* res=dummy;
        while(temp!=NULL){
            res->next= temp->next;
            res= res->next;
            temp->next= temp->next->next;
            temp= temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        copyinbw(head);
        connectrp(head);
        return getDCL(head);
    }
};