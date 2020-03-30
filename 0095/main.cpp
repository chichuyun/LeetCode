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
    vector<TreeNode*> helper(int m, int n) {
        if(n < m) return {nullptr};

        vector<TreeNode*> nodes;
        for(int i=m;i<=n;++i) {
            vector<TreeNode*> left = helper(m,i-1);
            vector<TreeNode*> right = helper(i+1,n);
            
            for(auto l : left) {
                for(auto r : right) {
                   TreeNode *root = new TreeNode(i);
                   root->left = l;
                   root->right = r;
                   nodes.push_back(root);
                }
            }
        }
        return nodes;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n<1) return {};
        return helper(1, n);;
    }
};