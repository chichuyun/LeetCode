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
    int depth(TreeNode* root, int& ans) {
        if(!root) return 0;
        int L=0, R=0;
        if(root->left) L = depth(root->left, ans);
        if(root->right) R = depth(root->right, ans);
        
        ans = max(L+R, ans);
        return max(L,R) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        depth(root, ans);
        return ans;
    }
};