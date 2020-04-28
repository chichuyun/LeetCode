/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node*,Node*> nums;
        queue<Node*> nodes, news;
        Node *root = new Node(node->val);
        nodes.push(node);
        news.push(root);
        nums[node] = root;
        while(!nodes.empty()) {
            Node *g = nodes.front();
            Node *f = news.front();
            nodes.pop();
            news.pop();
            for(auto n : g->neighbors) {
                if(nums.find(n)==nums.end()) {
                    Node *p = new Node(n->val);
                    f->neighbors.push_back(p);
                    news.push(p);
                    nodes.push(n);
                    nums[n] = p;
                } else {
                    f->neighbors.push_back(nums[n]);
                }
            }
        }
        return root;
    }
};