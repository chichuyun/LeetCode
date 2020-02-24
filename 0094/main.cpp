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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> r;
        vector<int> nums;
        TreeNode *p=root;
        
        while(p || !r.empty()) {
            while(p) {
                r.push(p);
                p = p->left;
            }
            if(!r.empty()) {
                p = r.top();
                nums.push_back(p->val);
                r.pop();
                p = p->right;
            }
        }
        return nums;
    }
};