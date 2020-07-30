/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> dfs(int& count, TreeNode* root, int& distance) {
        if(!root) return {};
        if(!root->left && !root->right) return {1};
        vector<int> lefts = dfs(count, root->left, distance);
        vector<int> rights = dfs(count, root->right, distance);
        
        for(int& l : lefts) {
            for(int& r : rights) {
                if(l+r <= distance) ++count;
            }
        }
        
        vector<int> nums;
        for(int& l : lefts) {
            if(l+1 < distance) nums.push_back(l+1);
        }
        for(int& r : rights) {
            if(r+1 < distance) nums.push_back(r+1);
        }
        
        return nums;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        if(!root) return 0;
        int count = 0;
        
        dfs(count, root, distance);
        
        return count;
    }
};