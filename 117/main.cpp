/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        if(root->left) {
            if(root->right) {
                root->left->next = root->right;
            } else {
                search(root->left, root->next);
            }
        }
        if(root->right) {
            search(root->right, root->next);
        }
        connect(root->right);
        connect(root->left);
    }
    
    void search(TreeLinkNode *root, TreeLinkNode *next) {
        while(next) {
            if(next->left) {
                root->next = next->left;
                return;
            }
            else if(next->right) {
                root->next = next->right;
                return;
            }
            next = next->next;
        }
    }
};
