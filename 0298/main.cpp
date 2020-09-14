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
    int maxCount;
    void dfs(TreeNode* root, int count) {
        maxCount = max(count, maxCount);

        if(root->left) {
            if(root->left->val == root->val+1) {
                dfs(root->left, count+1);
            } else {
                dfs(root->left, 1);
            }
        }

        if(root->right) {
            if(root->right->val == root->val+1) {
                dfs(root->right, count+1);
            } else {
                dfs(root->right, 1);
            }
        }
    }
public:
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        maxCount = 0;
        dfs(root, 1);

        return maxCount;
    }
};