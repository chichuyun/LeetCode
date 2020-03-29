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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> nodes;
        int count, res;
        nodes.push(root);
        while(!nodes.empty()) {
            count = nodes.size();
            res = nodes.front()->val;
            while(count--) {
                TreeNode* p = nodes.front();
                nodes.pop();
                if(p->left) nodes.push(p->left);
                if(p->right) nodes.push(p->right);        
            }
        }
        return res;
    }
};