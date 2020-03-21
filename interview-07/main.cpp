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
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int m, int l, int r) {
        if(r >= l) {
            TreeNode *root = new TreeNode(preorder[m]);
            int i=l;
            while(inorder[i]!=preorder[m]) ++i;
            root->left = build(preorder, inorder, m+1, l, i-1);
            root->right = build(preorder, inorder, m+i-l+1, i+1, r);
            return root;
        }
        return nullptr;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        TreeNode *root = build(preorder, inorder, 0, 0, preorder.size()-1);
        return root;
    }
};