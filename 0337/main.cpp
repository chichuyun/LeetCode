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
    unordered_map<TreeNode*, int> nodes;
    int dfs(TreeNode* root) {
        if(!root) return 0;
        if(nodes.count(root)) return nodes[root];

        int res1 = root->val;
        if(root->left) {
            res1 += dfs(root->left->left) + dfs(root->left->right);
        }
        if(root->right) {
            res1 += dfs(root->right->left) + dfs(root->right->right);
        }

        int res2 = dfs(root->left) + dfs(root->right);

        nodes[root] = max(res1, res2);

        return nodes[root];
    }
public:
    int rob(TreeNode* root) {
        return dfs(root);
    }
};