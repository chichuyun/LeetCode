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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p=head, *q;
// 头
        while(p && p->val==val) {
            q = p;
            p = p->next;
            delete q;
        }
// 中间 和 尾
        head = p;
        while(p && p->next) {
            if(p->next->val==val) {
                q = p->next;
                p->next = q->next;
                delete q;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};
