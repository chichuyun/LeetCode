/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<climits>
#include<algorithm>

class Solution {
private:
    int findMax(TreeNode* root, int& max_v) {
        if(!root) return 0;

        int left = findMax(root->left, max_v);
        int right = findMax(root->right, max_v);

        int num = left + right + root->val;
        int left_v = left + root->val;
        int right_v = right + root->val;

        int res;
        res = max(root->val, max(left_v, right_v));
        max_v = max(max(max_v, res), num);

        return res;
    }
public:
    int maxPathSum(TreeNode* root) {
        int max_v = INT_MIN;
        
        findMax(root, max_v);
        return max_v;
    }
};