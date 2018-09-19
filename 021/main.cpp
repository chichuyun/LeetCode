/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p=l1, *q=l2, *head=new ListNode(0), *t=head;
        
        if(!p)
            return q;
        else if(!q)
            return p;

        while(p && q) {
            if(p->val <= q->val) {
                t->next = p;
                p = p->next;
            } else {
                t->next = q;
                q = q->next;
            }
            t = t->next;
        }
        if(!p)
            t->next = q;
        else
            t->next = p;
        return head->next;
    }
};
