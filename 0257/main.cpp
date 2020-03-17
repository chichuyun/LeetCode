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
    vector<string> strs;
    void helper(TreeNode* root, string str) {
        if(!root->left) {
            if(!root->right) {
                str.pop_back();
                str.pop_back();
                strs.push_back(str);
            } else {
                str += to_string(root->right->val)+"->";
                helper(root->right, str);
            }
        } else {
            if(!root->right) {
                str += to_string(root->left->val)+"->";
                helper(root->left, str);
            } else {
                string temp(str);
                str += to_string(root->right->val)+"->";
                helper(root->right, str);
                temp += to_string(root->left->val)+"->";
                helper(root->left, temp);
            }
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return strs;
        string str;
        str += to_string(root->val)+"->";
        helper(root, str);
        return strs;
    }
};