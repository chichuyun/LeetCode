/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> nodes;
        TreeNode *p = root, *pre = nullptr, *l, *r;
        bool flag = true;

        while(!nodes.empty() || p) {
            while(p) {
                nodes.push(p);
                p = p->left;
            }

            if(!nodes.empty()) {
                p = nodes.top();
                nodes.pop();
                if(pre && pre->val > p->val) {
                    if(flag) {
                        l = pre;
                        flag = false;
                    }
                    r = p;
                }
                pre = p;
                p = p->right;
            }
        }
        swap(l->val, r->val);
    }
};