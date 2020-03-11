/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
private:
    void helper(vector<int>& nums, Node* root) {
        if(!root) return;
        
        nums.push_back(root->val);
        for(auto child : root->children) {
            helper(nums, child);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> nums;
        helper(nums, root);
        return nums;
    }
};