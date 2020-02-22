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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p=head, *t, *s, *q=new ListNode(0);
        
        if(!p || !p->next)
            return p;

        s = p->next;
        while(p && p->next) {
            t = p->next;
            q->next = t;
            p->next = t->next;
            t->next = p;
            
            q = p;
            p = p->next;
        }
        return s;
/* 递归(变量很少)
        ListNode* temp=new ListNode(0);
        if(!head || !head->next) {
            return head;
        }
        temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        return temp;
*/
/*
        if(!head || !head->next)
            return head;
        ListNode* right = swapPairs(head->next->next);
        ListNode* left = head->next;
        left->next = head;
        head->next = right;
        return left;
*/
    }
};
