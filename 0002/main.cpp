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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int con=0, temp, t1, t2;
        ListNode *l3=new ListNode(0), *t=l3, *p=l1, *q=l2;
        while(p!=nullptr || q!=nullptr) {
            t1=p!=nullptr?p->val:0;
            t2=q!=nullptr?q->val:0;
            temp = t1 + t2 + con;  // con = temp>=10 ? 1 : 0;
            if(temp >= 10) {       // temp = temp%10;
                t->next = new ListNode(temp-10);
                con = 1;
            } else {
                t->next = new ListNode(temp);
                con = 0;
            }
            if(p!=nullptr)
                p = p->next;
            if(q!=nullptr)
                q = q->next;
            t = t->next;
        }
        if(con==1) {
            t->next = new ListNode(1);
        } 
        
        t = l3;
        l3 = l3->next;
        delete t;

        return l3;
    }
};
