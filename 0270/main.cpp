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
    int res;
    double minValue;
    void dfs(TreeNode* root, double& target) {
        double num = root->val - target;
        if(num > 0) {
            if(minValue > num) {
                res = root->val;
                minValue = num;
            }
            if(root->left) dfs(root->left, target);
        } else {
            num = -num;
            if(minValue > num) {
                res = root->val;
                minValue = num;
            }
            if(root->right) dfs(root->right, target);
        }
    }
public:
    int closestValue(TreeNode* root, double target) {
        res = root->val;
        minValue = abs(res - target);
        dfs(root, target);
        return res;
    }
};