struct TrieNode {
    bool flag;
    unordered_map<char, TrieNode*> children;
    TrieNode() : flag(false) {};
};


class WordDictionary {
private:
    TrieNode *root, *p;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        p = root;
        for(int i=0;i<word.size();++i) {
            if(!p->children[word[i]]) {
                p->children[word[i]] = new TrieNode();
            }
            p = p->children[word[i]];
        }
        p->flag = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(helper(root, word, 0)) return true;
        return false;
    }
    
    bool helper(TrieNode* p, string& word, int n) {
        if(n == word.size()) {
            if(p) return p->flag;
            return false;
        } else {
            if(word[n]!='.') {
                if(p && p->children[word[n]]) {
                    return helper(p->children[word[n]], word, n+1);
                } else {
                    return false;
                }
            } else {
                bool flag = false;
                if(p) {
                    for(auto c : p->children) {
                        flag = flag || helper(c.second, word, n+1);
                    }
                }
                return flag;
            }
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */