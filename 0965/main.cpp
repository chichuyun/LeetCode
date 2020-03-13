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
    bool helper(TreeNode* root, int val) {
        if(!root) return true;

        if(root->val!=val) return false;

        return helper(root->left, val) && helper(root->right, val);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;

        return helper(root, root->val);
    }
};