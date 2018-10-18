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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0)
            return head;
        
        ListNode *p=head, *q;
        int length=0;
        while(p && p->next) {
            p = p->next;
            length++;
        }
        length++;
        q = p;
        q->next = head;
        k = length - k%length;
        p = head;
        for(int i=1;i<k;i++)
            p = p->next;
        q = p->next;
        p->next = nullptr;
        return q;
    }
};
