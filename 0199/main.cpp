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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> nums;
        if(!root) return nums;
        queue<TreeNode*> nodes;
        TreeNode* temp;
        int count;
        
        nodes.push(root);
        while(!nodes.empty()) {
            count = nodes.size();
            while(count) {
                temp = nodes.front();
                if(temp->left) nodes.push(temp->left);
                if(temp->right) nodes.push(temp->right);

                if(count==1) nums.push_back(temp->val);
                nodes.pop();
                --count;
            }
        }
        return nums;
    }
};