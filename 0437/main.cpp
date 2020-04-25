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
    int count = 0;
    void Sum(TreeNode* root, int sum) {
        if(!root) return;
        sum -= root->val;
        if(sum == 0) {
            ++count;
        }
        Sum(root->left, sum);
        Sum(root->right, sum);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        Sum(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return count;
    }
};