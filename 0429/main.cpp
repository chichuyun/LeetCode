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
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<Node*> nodes;
        vector<int> nums;
        Node* temp;
        int count;
        
        nodes.push(root);
        while(!nodes.empty()) {
            nums.clear();
            count = nodes.size();
            while(count) {
                temp = nodes.front();
                nums.push_back(temp->val);
                nodes.pop();
                for(auto child : temp->children) {
                    if(child) nodes.push(child);
                }
                --count;
            }
            res.push_back(nums);
        }
        return res;
    }
};