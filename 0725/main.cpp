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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> nodes;
        int len = 0;
        ListNode *p = root;
        while(p) {++len; p = p->next;}
        int num = len/k, con = len%k;
        p = root;
        while(k--) {
            nodes.push_back(p);
            int loop = num + (con-- > 0) - 1;
            while(p && loop--) {
                p = p->next;
            }
            if(p) {
                ListNode *t = p->next;
                p->next = nullptr;
                p = t;
            }
        }
        return nodes;
    }
};