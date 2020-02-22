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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p=new ListNode(0), *q, *newhead=p, *t;
        p->next = head;
        while(p && p->next) {
            if(p->next->val < x) {
                p = p->next;
            } else {
                break;
            }
        }
        q = p;
        while(p && p->next) {
            if(p->next->val < x) {
                t = p->next;
                p->next = p->next->next;
                t->next = q->next;
                q->next = t;
                q = q->next;
            } else {
                p = p->next;
            }
        }
        return newhead->next;
    }
};
