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
    queue<pair<int, double>> nums;
    int count;
    void dfs(TreeNode* root, double& target, int& k) {
        if(root->left) dfs(root->left, target, k);
        double num = abs(root->val - target);
        if(nums.size() < k) {
            nums.emplace(root->val, num);
        } else {
            if(nums.front().second > num) {
                nums.pop();
                nums.emplace(root->val, num);
            } else {
                return;
            }
        }
        if(root->right) dfs(root->right, target, k);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        count = 0;
        dfs(root, target, k);

        vector<int> res;
        while(k--) {
            res.push_back(nums.front().first);
            nums.pop();
        }
        return res;
    }
};