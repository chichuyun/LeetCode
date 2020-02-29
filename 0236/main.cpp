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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;

/*
        vector<TreeNode*> nums1, nums2;
        int len, i;
        
        if(searchTree(root, p->val, nums1)) nums1.push_back(root);
        if(searchTree(root, q->val, nums2)) nums2.push_back(root);
        
        reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());
        len = nums1.size() < nums2.size() ? nums1.size() : nums2.size();
        
        for(i=0;i<len;i++) {
            if(nums1[i]!=nums2[i]) {
                return nums1[i-1];
            }
        }
        return nums1[i-1];
    }
    
    bool searchTree(TreeNode* root, int val, vector<TreeNode*>& nums) {
        if(!root) {
            return false;
        } else if(root->val==val) {
            return true;
        } else if(searchTree(root->left, val, nums)) {
            nums.push_back(root->left);
            return true;
        } else if(searchTree(root->right, val, nums)) {
            nums.push_back(root->right);
            return true;
        }
        return false;
*/
    }
};