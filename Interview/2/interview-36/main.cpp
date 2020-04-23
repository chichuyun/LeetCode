/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        Node *head = new Node();
        Node *p = head, *t;
        stack<Node*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            root = nodes.top();
            while(root->left) {  // first push in
                nodes.push(root->left);
                t = root;
                root = root->left;
                t->left = nullptr;
            }
            p->right = root;  // second pop out
            root->left = p;
            p = p->right;
            nodes.pop();
            if(root->right) {  // third push in
                nodes.push(root->right);
                t = root;
                root = root->right;
                t->right = nullptr;
            }
        }
        root = head->right;
        p->right = root;
        root->left = p;
        return head->right;
    }
};