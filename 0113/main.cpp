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
    vector<vector<int>> res; 
    void helper(TreeNode* root, vector<int>& nums, int sum) {
        if(!root->left && !root->right) {
            if(sum==root->val) {
                nums.push_back(root->val);
                res.push_back(nums);
                nums.pop_back();
            }
            return;
        }
        if(root->left) {
            nums.push_back(root->val);
            helper(root->left, nums, sum-root->val);
            nums.pop_back();
        }
        if(root->right) {
            nums.push_back(root->val);
            helper(root->right, nums, sum-root->val);
            nums.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return res;
        vector<int> nums;
        helper(root, nums, sum);
        return res;
    }
};