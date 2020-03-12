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
    TreeNode* helper(vector<int>& nums, int i, int j) {
        if(i>j) return nullptr;
        int m = (i + j)/2;
        TreeNode *node = new TreeNode(nums[m]);
        node->left = helper(nums, i, m-1);
        node->right = helper(nums, m+1, j);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};