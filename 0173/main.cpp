/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> r;
    TreeNode *p;
    int num;
public:
    BSTIterator(TreeNode* root) {
        p = root;
    }
    
    /** @return the next smallest number */
    int next() {
        while(p) {
            r.push(p);
            p = p->left;
        }
        if(!r.empty()) {
            p = r.top();
            num = p->val;
            r.pop();
            p = p->right;
        }
        return num;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return p || !r.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */