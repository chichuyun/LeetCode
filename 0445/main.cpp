/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int helper(ListNode* p, int m, ListNode* q, int n, ListNode* head) {
        if(m==0 && n==0) return -1;
        head->next = new ListNode(0);
        head = head->next;
        int num, val;
        if(m > n) {
            num = helper(p->next, m-1, q, n, head);
            val = p->val + num;
        } else {
            num = helper(p->next, m-1, q->next, n-1, head);
            if(num==-1) num = 0;
            val = p->val + q->val + num;
        }
        head->val = val%10;
        return val/10;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *q = l1, *p = l2;
        int len1=0, len2 = 0, num;
        while(q) { ++len1; q = q->next; }
        while(p) { ++len2; p = p->next; }
        ListNode *head = new ListNode(0);
        if(len1<len2) {
            num = helper(l2, len2, l1, len1, head);
        } else {
            num = helper(l1, len1, l2, len2, head);
        }
        if(num==1) {
            head->val = 1;
        } else {
            head = head->next;
        }
        return head;
    }
};