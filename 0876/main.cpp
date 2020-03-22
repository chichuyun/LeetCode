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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

/*
        if(!head) return head;
        int len=0;
        ListNode *p=head;
        while(p) {
            ++len;
            p = p->next;
        }
        
        p = head;
        len = len/2;
        for(int i=0;i<len;++i) {
            p = p->next;
        }
        return p;
*/
    }
};