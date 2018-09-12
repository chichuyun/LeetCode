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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p=head, *q=head;

        for(int i=0;i<n;i++) p = p->next;

        if(p==nullptr) {
            p = head->next;
            delete head;
            return p;
        }

        while(p->next!=nullptr) {
            p = p->next;
            q = q->next;
        }
        p = q->next;
        q->next = p->next;
        delete p;
        return head;
    }
};
