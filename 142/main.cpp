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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p=head, *q=head;
        bool flag = true;

        while(p!=nullptr && p->next!=nullptr) {
            p = p->next->next;
            q = q->next;
            if(p==q) {
                flag = false;
                break;
            }
        }
        if(flag)
            return nullptr;
        p = head;
        //尽量减少判断,另外注意次序
        while(p!=q) {                
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
