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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> r;
        TreeNode *p=root, *last;
        vector<vector<int>> nums;
        if(!root) return nums;
        
        r.push(root);
        last = root;
        while(!r.empty()) {
            last = r.back();
            vector<int> num;
            do {
                p = r.front();
                if(p->left) r.push(p->left);
                if(p->right) r.push(p->right);
                num.push_back(p->val);
                r.pop();
            } while(p!=last);
            nums.push_back(num);
        }
        return nums;
    }
};