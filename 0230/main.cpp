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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> nodes;
        int count = 0;
        TreeNode *p = root;
        while(p || !nodes.empty()) {
            while(p) {
                nodes.push(p);
                p = p->left;
            }
            ++count;
            if(count==k) return nodes.top()->val;
            p = nodes.top()->right;
            nodes.pop();
        }
        return 0;
    }
};