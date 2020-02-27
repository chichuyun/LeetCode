/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node *c, *p, *t, *n=head;
        
        while(n) {
            if(n->child) {
                c = n->child;
                t = n->next;
                n->next = c;
                c->prev = n;
                n->child = nullptr;
                p = flatten(c);
                // we also can return the end of child to save time.
                while(p && p->next) p = p->next; 
                p->next = t;
                if(t) t->prev = p;
            } else {
                n = n->next;
            }
        }
        
        return head;
    }
};