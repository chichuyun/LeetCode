/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* helper(ListNode *head, int m, int n) {
        if(m>n) return nullptr;
        if(m==n) return new TreeNode(head->val);
        int len = m+(n-m)/2, k = (n-m)/2;  // len = (n+m)/2
        ListNode *p = head;
        while(k--) p = p->next;
        TreeNode *root = new TreeNode(p->val);
        
        TreeNode *left = helper(head, m, len-1);
        TreeNode *right = helper(p->next, len+1, n);
        root->left = left;
        root->right = right;

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *p = head;
        int len = 0;
        while(p) {
            ++len;
            p = p->next;
        }
        TreeNode *root = helper(head, 0, len-1);
        return root;
    }
};