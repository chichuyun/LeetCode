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
/* 迭代的方式
        ListNode *p=head, *q=nullptr;
        while(p) {
            ListNode *t=new ListNode(p->val);
            t->next = q;
            q = t;
            p = p->next;
        }
        return q;
*/
// 递归的方式
        if(!head || !head->next)
            return head;
        ListNode *t = head;
        ListNode *p = reverseList(head->next);
        t->next->next = t;
        t->next = nullptr;
        return p;
    }
};
