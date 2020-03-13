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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> nodes;
        int count, res=0;
        TreeNode* temp;

        nodes.push(root);
        while(!nodes.empty()) {
            count = nodes.size();
            while(count--) {
                temp = nodes.front();
                res += 1;
                if(temp->left) nodes.push(temp->left);
                if(temp->right) nodes.push(temp->right);

                nodes.pop();
            }
        }
        return res;
    }
};