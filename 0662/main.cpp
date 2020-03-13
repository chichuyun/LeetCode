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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*,int>> nodes;
        TreeNode* temp;
        long count, max=1, num;
        nodes.emplace(root,1);
        while(!nodes.empty()) {
            count = nodes.size();
            num = nodes.back().second - nodes.front().second+1;
            max = max > num ? max : num;
            while(count--) {
                temp = nodes.front().first;
                num = nodes.front().second;
                if(temp->left) nodes.emplace(temp->left,num+num-1);
                if(temp->right) nodes.emplace(temp->right,num+num);
                nodes.pop();
            }
        }
        return max;
    }
};