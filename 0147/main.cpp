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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newhead = new ListNode(0);
        ListNode *p, *t;
        while(head) {
            p = newhead;
            while(p->next && p->next->val<head->val) p = p->next;
            t = p->next;
            p->next = head;
            head = head->next;
            p->next->next = t;
        }
        return newhead->next;
    }
};