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
    bool helper(TreeNode* root, int& k, unordered_set<int>& nums) {
        if(!root) return false;
        if(nums.find(k - root->val)!=nums.end()) return true;
        nums.insert(root->val);
        return helper(root->left, k, nums) || helper(root->right, k, nums);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        unordered_set<int> nums;
        nums.insert(root->val);
        return helper(root->left, k, nums) || helper(root->right, k, nums);
    }
};