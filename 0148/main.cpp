 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
class Solution {
    ListNode* mergeList(ListNode *p, ListNode *q) {
        ListNode *head=new ListNode(0), *k;
        k = head;
        while(p && q) {
            if(p->val < q->val) {
                k->next = p;
                p = p->next;
                k = k->next;
            } else {
                k->next = q;
                q = q->next;
                k = k->next;
            }
        }
        if(p) {
            k->next = p;
        } else {
            k->next = q;
        }
        return head->next;
    }

    ListNode* helper(ListNode* head, int len) {
        if(len<2) {           // zero or one
            return head;
        } else if(len==2) {   // only two
            if(head->val > head->next->val) swap(head->val, head->next->val);
            return head;
        }
        int left, right;
        left = len/2;
        right = len - left;
        ListNode *p = head;
        for(int i=1;i<left;++i) {
            p = p->next;
        }
        ListNode *q = p->next;
        p->next = nullptr;
        
        ListNode *t1 = helper(head, left);
        ListNode *t2 = helper(q, right);
        return mergeList(t1, t2);
    }
public:
    ListNode* sortList(ListNode* head) {
        int len=0;
        ListNode *p=head;
        while(p) {
            ++len;
            p = p->next;
        }
        return helper(head, len);;
    }
};