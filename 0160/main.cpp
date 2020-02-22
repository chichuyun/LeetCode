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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p=headA,*q=headB;
        int lenA=0, lenB=0, len;
        while(p) {
            p = p->next;
            lenA++;
        }
        while(q) {
            q = q->next;
            lenB++;
        }
        p = headA; q = headB;
        len = lenA - lenB;
        if(len>0) {
            for(int i=0;i<len;i++)
                p = p->next;
        } else {
            for(int i=0;i<-len;i++)
                q = q->next;
        }
        while(p!=q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
