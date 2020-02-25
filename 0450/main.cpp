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
    TreeNode* deleteNode(TreeNode* root, int key) {
        int num, flag=0;
        TreeNode *p=root, *t, *k;
        
        if(!p) return p;
        if(p->val==key && !(p->left && p->right)) {
            if(p->left) {
                p = p->left;
            } else {
                p = p->right;
            }
            delete root;
            return p;
        }
        
        while(p->val!=key) {
            k = p; // the father node of this node
            if(p->val<key && p->right) {  // go right
                p = p->right;
                flag = 1;
            } else if(p->left) { // go left
                p = p->left;
                flag = 2;
            } else {  // do not find this node
                return root; 
            }
        }
        cout<<"p: "<<p->val<<endl;
        cout<<"k: "<<k->val<<endl;
        cout<<"f: "<<flag<<endl;
        if(p->right && p->left) {
            t = p;
            k = p;
            p = p->right;
            flag = 1;
            if(p->left) {
                flag = 2;
                k = k->right;
                p = p->left;
            }
            while(p->left) {
                k = k->left;
                p = p->left;
            }
            t->val = p->val;
        }
        t = p;  // zero or one node
        if(p->left) {
            if(flag==1) {
                k->right = p->left;
            } else {
                k->left = p->left;
            }
        } else {
            if(flag==1) {
                k->right = p->right;
            } else {
                k->left = p->right;
            }
        }
        delete t; // free the node memory
        return root;
/*
        if (!root) return nullptr;
        if (root->val == key) {
            if (root->left) {
                TreeNode* node = root->left;
                while (node->right) node = node->right;
                node->right = root->right;
                return root->left;
            }
            return root->right;
        }
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        return root;
*/
    }
};