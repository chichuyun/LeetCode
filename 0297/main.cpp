/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        TreeNode *p=root;
        queue<TreeNode*> r;
        int count, f=1, g;
        
        if(!root) return s;
        r.push(p);
        while(!r.empty() && f) {
            g = 0;
            count = r.size();
            do {
                p = r.front();
                if(p) {
                    s += to_string(p->val);
                    s.push_back(',');
                    if(p->left) {
                        r.push(p->left);
                        g = 1;
                    } else {
                        r.push(nullptr);
                    }
                    if(p->right) {
                        r.push(p->right);
                        g = 1;
                    } else {
                        r.push(nullptr);
                    }
                } else {
                    s += "null,";
                }
                r.pop();
                count--;
            } while(count);
            f = g;
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int count=1, i=0, j=0, num=0, stop=data.size()-1;
        string n;
        queue<TreeNode*> r;
        TreeNode *p, *root=new TreeNode(0);
        
        if(data=="") return nullptr;
        while(data[j]!=',') ++j;
        n = data.substr(i,j);
        root->val = atoi(n.c_str());
        r.push(root);
        while(!r.empty()) {
            num = 0;
            if(j==stop) break;
            do {
                p = r.front();
                
                ++j;
                i = j;
                while(data[j]!=',') ++j;
                n = data.substr(i,j-i);
                if(n!="null") {
                    r.push(new TreeNode(atoi(n.c_str())));
                    ++num;
                    p->left = r.back();
                } 
                
                ++j;
                i = j;
                while(data[j]!=',') ++j;
                n = data.substr(i,j-i);
                if(n!="null") {
                    r.push(new TreeNode(atoi(n.c_str())));
                    ++num;
                    p->right = r.back();
                }
                r.pop();
                count--;
            } while(count);
            count = num;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));