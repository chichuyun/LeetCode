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
    void helper(TreeNode* root, int& count) {
        if(root) {
            if(root->left) {
                if(!root->left->left && !root->left->right) {
                    count += root->left->val;
                } else {
                    helper(root->left, count);
                }
            }
            if(root->right) {
                helper(root->right, count);
            }
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        helper(root, count);
        return count;
    }
};