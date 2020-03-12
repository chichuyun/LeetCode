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
    int depth(TreeNode* root, int& flag) {
        if(!root) return 0;
        
        int left = depth(root->left, flag);
        int right = depth(root->right, flag);
        if(abs(left-right)>1) {
            flag = 0;
        }
        
        return max(left,right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int flag = 1;
        depth(root, flag);
        if(flag) {
            return true;
        } else {
            return false;
        }
    }
};