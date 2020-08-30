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
    int getDecimalValue(ListNode* head) {
        if(!head) return 0;
        ListNode *p = head;
        int num = 0;
        while(p) {
            num <<= 1;
            num |= p->val;
            p = p->next;
        }
        return num;
    }
};