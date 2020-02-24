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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nums;
        TreeNode *p = root;
        stack<TreeNode*> r;
        
        while(p || !r.empty()) {
            while(p) {
                r.push(p);
                nums.push_back(p->val);
                p = p->left;
            }
            if(!r.empty()) {
                p = r.top();
                r.pop();
                p = p->right;
            }
        }
        return nums;
    }
/*    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nums;
        preorder(root, nums);
        return nums;
    }
    void preorder(TreeNode* root, vector<int>& nums) {
        if(!root) return;
        nums.push_back(root->val);
        preorder(root->left, nums);
        preorder(root->right, nums);
    }
*/
};