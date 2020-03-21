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
    vector<int> reversePrint(ListNode* head) {
        vector<int> nums;
        if(!head) return nums;
        ListNode *p=new ListNode(0), *t;
        while(head) {
            t = p->next;
            p->next = head;
            head = head->next;
            p->next->next = t;
        }
        p = p->next;
        while(p) {
            nums.push_back(p->val);
            p = p->next;
        }
        return nums;
    }
};