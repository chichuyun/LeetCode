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
    void deleteNode(ListNode* node) {
        while(node->next && node->next->next) {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        ListNode* end = node->next;
        node->next = nullptr;
        delete end;
/* method 只用交换一个值
        node->val = node->next->val;
        node->next = node->next->next;
*/
    }
};