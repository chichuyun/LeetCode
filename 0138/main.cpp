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
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        
        Node *p=head, *p0, *k, *k0, *t, *newhead;
        
        newhead = new Node(0);
        newhead->next = new Node(p->val);
        k = newhead->next;
        p = p->next;
        while(p) {
            k->next = new Node(p->val);
            k = k->next;
            p = p->next;
        }
        
        p = head;
        k = newhead->next;
        while(p) {            
            p0 = head;
            k0 = newhead->next;
            t = p->random;
            if(!t) {
                k->random = nullptr;
            } else {
                while(p0!=t) {
                    p0 = p0->next;
                    k0 = k0->next;
                }
                k->random = k0;
            }
            k = k->next;
            p = p->next;
        }
        
        return newhead->next;
    }
};