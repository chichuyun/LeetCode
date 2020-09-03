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
    int dfs(TreeNode* root, int& countMax) {
        if(!root) return 0;
        
        int left = dfs(root->left, countMax);
        int right = dfs(root->right, countMax);
        int f_l = false, f_r = false;

        if(root->left && root->left->val == root->val) f_l = true;
        if(root->right && root->right->val == root->val) f_r = true;
        if(f_l && f_r) {
            countMax = max(countMax, left+right+1);
            return max(left, right) + 1;;
        } else if(f_l) {
            countMax = max(countMax, left+1);
            return left + 1;
        } else if(f_r) {
            countMax = max(countMax, right+1);
            return right + 1;
        }
        return 1;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int countMax = 1;
        dfs(root, countMax);
        return countMax-1;
    }
};