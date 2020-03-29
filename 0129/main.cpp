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
private:
    void helper(TreeNode* root, int& count, int num) {
        if(root) {
            int n = 10*num + root->val;
            if(!root->right && !root->left) {
                count += n;
            } else {
                if(root->right) helper(root->right, count, n);
                if(root->left) helper(root->left, count, n);
            }
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        helper(root, count, 0);
        return count;
    }
};