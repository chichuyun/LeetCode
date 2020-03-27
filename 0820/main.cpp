struct TrieNode {
    bool flag;
    int depth;
    unordered_map<char, TrieNode*> children;
    TrieNode() : flag(false), depth(0) {};
};

class Trie {
private:
    TrieNode *root, *p;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        p = root;
        reverse(word.begin(), word.end());
        for(int i=0;i<word.size();++i) {
            if(!p->children[word[i]]) {
                p->children[word[i]] = new TrieNode();
            }
            p = p->children[word[i]];
        }
        p->flag = true;
        p->depth = word.size() + 1;
    }

    int getCount() {
        queue<TrieNode*> nodes;
        int count, num=0;
        nodes.push(root);
        while(!nodes.empty()) {
            count = nodes.size();
            while(count--) {
                p = nodes.front();
                nodes.pop();
                for(auto c : p->children) {
                    nodes.push(c.second);
                }
                if(p->children.size()==0) {
                    num += p->depth;
                }
            }
        }
        return num;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie *tree = new Trie();
        for(string str : words) tree->insert(str);
        return tree->getCount();
    }
};