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
        
        for(auto child : root->children) {
            helper(nums, child);
        }
        nums.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> nums;
        helper(nums, root);
        return nums;
    }
};