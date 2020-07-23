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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nums;

        if(!root) return nums;
        stack<TreeNode*> nodes;
        TreeNode* p = root;
        
        while(p || !nodes.empty()) {
            while(p) {
                nums.push_back(p->val);
                if(p->left) nodes.push(p->left);
                p = p->right;
            }

            if(!nodes.empty()) {
                p = nodes.top();
                nodes.pop();
            }
        }

        reverse(nums.begin(), nums.end());
        return nums;
    }
};