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
    bool helper(TreeNode* s, TreeNode* p) {
        if((!s && p) || (s && !p)) return false;
        if(!s && !p) {
            return true;
        } else if(p->val==s->val) {
            return helper(s->left, p->left) && helper(s->right, p->right);
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(s->val == t->val) {
            if(helper(s, t)) return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};