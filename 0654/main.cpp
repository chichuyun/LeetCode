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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        stack<TreeNode*> nodes;
        TreeNode *t, *p, *k, *root;
        
        t = new TreeNode(nums[0]);
        nodes.push(t);
        root = nodes.top();
        for(int i=1;i<nums.size();++i) {
            t = new TreeNode(nums[i]);
            if(t->val>root->val) root = t;
            if(nodes.top()->val>nums[i]) {
                nodes.top()->right = t;
                nodes.push(t);
            } else {
                while(!nodes.empty() && nodes.top()->val<nums[i]) {
                    p = nodes.top();
                    nodes.pop();
                }
                t->left = p;
                if(!nodes.empty()) {
                    k = nodes.top();
                    k->right = t;
                }
                nodes.push(t);
            }
        }
        return root;
    }
};