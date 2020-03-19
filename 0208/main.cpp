struct TrieNode {
    string val;
    bool flag;
    unordered_map<char, TrieNode*> children;
    TrieNode(string x) : val(x), flag(false) {};
};

class Trie {
private:
    TrieNode *root, *p;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode("");
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        p = root;
        for(int i=0;i<word.size();++i) {
            if(!p->children[word[i]]) {
                p->children[word[i]] = new TrieNode(word.substr(0,i));
            }
            p = p->children[word[i]];
        }
        p->flag = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        p = root;
        for(int i=0;i<word.size();++i) {
            if(p->children[word[i]]) {
                p = p->children[word[i]];
            } else {
                return false;
            }
        }
        if(p->flag) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        p = root;
        for(int i=0;i<prefix.size();++i) {
            if(p->children[prefix[i]]) {
                p = p->children[prefix[i]];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */