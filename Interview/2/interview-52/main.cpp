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
        int lenA=0, lenB=0;
        ListNode *p=headA, *q=headB;
        while(p) {
            p = p->next;
            ++lenA;
        }
        while(q) {
            q = q->next;
            ++lenB;
        }

        p = headA;
        q = headB;
        if(lenA>lenB) {
            for(int i=0;i<lenA-lenB;++i) {
                p = p->next;
            }
        } else {
            for(int i=0;i<lenB-lenA;++i) {
                q = q->next;
            }
        }
        int len = min(lenA, lenB);
        for(int i=0;i<len;++i) {
            if(p==q) return p;
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
};