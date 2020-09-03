/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool dfs(TreeNode* root, int& count) {
        if(!root) return true;

        bool left = dfs(root->left, count);
        bool right = dfs(root->right, count);
        if(root->left && root->left->val!=root->val ||
           root->right && root->right->val!=root->val)
           return false;
        if(left && right) ++count;
        return true;

    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }
};