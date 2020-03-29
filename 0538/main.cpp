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
    void helper(TreeNode* root, int& num) {
        if(!root) return;
        helper(root->right, num);
        num += root->val;
        root->val = num;
        helper(root->left, num);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int num=0;
        helper(root, num);
        return root;
    }
};