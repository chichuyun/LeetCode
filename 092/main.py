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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || m==n)
            return head;
        ListNode *p=new ListNode(0), *q, *t, *newhead=p;
        p->next = head;
        for(int i=1;i<m;i++)
            p = p->next;
        
        q = p->next;
        for(int i=m;i<n;i++) {
            t = q->next;
            q->next = q->next->next;
            t->next = p->next;
            p->next = t;
        }
        return newhead->next;
    }
};
