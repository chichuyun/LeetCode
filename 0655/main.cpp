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
    vector<vector<string>> res;

    int getDepth(TreeNode* root) {
        if(!root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }

    void helper(TreeNode* root, int m, int n, int k) {
        if(!root) return;
        int num = (n + m) >> 1;
        res[k][num] = to_string(root->val);
        helper(root->left, m, num, k+1);
        helper(root->right, num, n, k+1);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root) return res;
        int depth = getDepth(root);
        int width = pow(2, depth) - 1;
        res.resize(depth, vector<string>(width,""));

        helper(root, 0, width, 0);
        return res;
    }
};