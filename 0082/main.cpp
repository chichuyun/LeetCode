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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode *p=head, *q;
        vector<int> num;
        bool flag=true;
        while(p && p->next) {
            if(p->val == p->next->val) {
                if(flag)
                    num.push_back(p->val);
                q = p->next;
                p->next = q->next;
                delete q;
                flag = false;
            } else {
                p = p->next;
                flag = true;
            }
        }

        p = new ListNode(0);
        p->next = head;
        ListNode *t=p;

        vector<int>::iterator n;
        for(n=num.begin(); n<num.end(); n++) {
            while(p && p->next) {
                if(p->next->val == *n) {
                    q = p->next;
                    p->next = q->next;
                    delete q;
                    break;
                } else {
                    p = p->next;
                }
            }
        }
        return t->next;
    }
};
