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
    void reorderList(ListNode* head) {
        int len=0;
        ListNode *p = head;
        while(p) {++len; p = p->next;}
        int sublen = len/2 + len%2;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        p = newhead;
        while(sublen--) {
            p = p->next;
        }
        ListNode *subhead = new ListNode(0), *q = p->next;
        p->next = nullptr;
        while(q) {  // reverse subhead List
            ListNode *t = subhead->next;
            subhead->next = q;
            q = q->next;
            subhead->next->next = t;
        }
        subhead = subhead->next;
        sublen = len/2;
        while(sublen--) { // link two List
            ListNode *t = head->next;
            head->next = subhead;
            subhead = subhead->next;
            head = head->next;
            head->next = t;
            head = head->next;
        }
    }
};