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
    void flatten(TreeNode* root) {
        TreeNode *p=root, *t, *k;
        while(p) {
            if(p->left) {
                k = p->left;
                t = p->right;
                while(k->right) k = k->right;
                p->right = p->left;
                k->right = t;
                p->left = nullptr; // this is necessary!
            }
            p = p->right;
        }
    }
};