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
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode *p=new ListNode(0), *t;
        while(head) {
            t = p->next;
            p->next = head;
            head = head->next;
            p->next->next = t;
        }
        return p->next;
    }
};