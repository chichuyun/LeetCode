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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> r;
        TreeNode *p=root;
        vector<vector<int>> nums;
        int count, n;
        
        if(!root) return nums;
        r.push(root);
        count = 1;
        while(!r.empty()) {
            vector<int> num;
            n = count;
            count = 0;
            while(n) {
                p = r.front();
                num.push_back(p->val);
                if(p->left) {
                    r.push(p->left);
                    count++;
                }
                if(p->right) {
                    r.push(p->right);
                    count++;
                }
                r.pop();
                n--;
            }
            nums.push_back(num);
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};