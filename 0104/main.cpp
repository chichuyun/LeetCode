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
    void dfs(TreeNode* root, int depth, int& count) {
        if(!root) return;
        if(!root->right && !root->left) {
            count = max(depth+1, count);
            return;
        }

        dfs(root->left, depth+1, count);
        dfs(root->right, depth+1, count);
    }
public:
    int maxDepth(TreeNode* root) {
        int count = 0;

        dfs(root, 0, count);

        return count;
    }
};