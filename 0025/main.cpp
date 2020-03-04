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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newhead=new ListNode(0), *subhead;
        ListNode *p, *q, *t, *tail;
        newhead->next = head;

        subhead = newhead;
        while(true) {
            tail = subhead;
            for(int i=0;i<k;++i) {  // at least k nodes
                if(tail->next) {
                    tail = tail->next;
                } else {
                    return newhead->next;
                }
            }
            tail = tail->next;  // tail
            p = subhead;
            q = subhead->next;
            p->next = tail;  // insert nodes between subhead and tail
            for(int i=0;i<k;++i) {
                t = p->next;
                p->next = q;
                q = q->next;
                p->next->next = t;
            }
            for(int i=0;i<k;++i) subhead = subhead->next;
        }
        return nullptr;
    }
};