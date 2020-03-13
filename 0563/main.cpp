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
    int helper(TreeNode* root, int& count) {
        if(!root) return 0;

        int left = helper(root->left, count);
        int right = helper(root->right, count);
        count += abs(left-right);

        return left + right + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        int count=0;
        helper(root, count);
        return count;
    }
};