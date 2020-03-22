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
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return head;
        ListNode *p = new ListNode(0);
        p->next = head;
        
        ListNode *t = p;
        while(p->next) {
            if(p->next->val==val) {
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return t->next;
    }
};