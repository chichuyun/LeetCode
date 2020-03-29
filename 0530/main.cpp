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
    int getMinimumDifference(TreeNode* root) {
        int num = numeric_limits<int>::max();

        queue<int> nums;
        TreeNode *p = root;
        stack<TreeNode*> nodes;
        while(p || !nodes.empty()) {
            while(p) {
                nodes.push(p);
                p = p->left;
            }
            if(!nodes.empty()) {
                p = nodes.top();
                nums.push(p->val);
                nodes.pop();
                p = p->right;
            }
            if(nums.size()==2) {
                num = min(num, nums.back()-nums.front());
                nums.pop();
            }
        }

        return num;
    }
};