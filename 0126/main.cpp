class Solution {
private:
    int depth;
    vector<vector<string>> strs;
    unordered_map<string, bool> words;
    unordered_map<string, int> wordCount;
    unordered_map<string, vector<string>> wordMap;

    void dfs(string& endWord, int& w, vector<string>& str, int deep, string& node) {
        if(deep == depth) return;
        if(node == endWord) {
            strs.push_back(str);
            return;
        }

        ++deep;
        for(int i=0; i<w; ++i) {
            string sub = node.substr(0,i) + "*" + node.substr(i+1, w-i-1);
            if(wordMap.count(sub)) {
                for(string& s : wordMap[sub]) {
                    if(words[s] && deep == wordCount[s]) {
                        str.push_back(s);
                        words[s] = false;
                        dfs(endWord, w, str, deep, s);
                        str.pop_back();
                        words[s] = true;
                    }
                }
            }
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.empty()) return strs;
        
        // initialization
        int w = beginWord.size();
        for(string& s : wordList) {
            for(int i=0; i<w; ++i) {
                wordMap[s.substr(0,i) + "*" + s.substr(i+1, w-i-1)].push_back(s);
            }
        }
        for(string& s : wordList) words[s] = true;
        for(string& s : wordList) wordCount[s] = INT_MAX;
        
        // calculate the minimum depth and path
        queue<string> nodes;
        nodes.push(beginWord);
        int count = 0;
        
        while(!nodes.empty()) {
            int n = nodes.size();
            ++count;
            while(n--) {
                string node = nodes.front();
                nodes.pop();
                if(node == endWord) {
                    depth = count;
                } else {
                    for(int i=0; i<w; ++i) {
                        string sub = node.substr(0,i) + "*" + node.substr(i+1, w-i-1);
                        if(wordMap.count(sub)) {
                            for(string& s : wordMap[sub]) {
                                if(words[s]) {
                                    nodes.push(s);
                                    wordCount[s] = min(wordCount[s], count);
                                    words[s] = false;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        // collect the strings
        for(string& s : wordList) words[s] = true;
        if(depth==0 || wordCount.count(endWord)==0) return strs;
        vector<string> str = vector<string>(1, beginWord);        
        dfs(endWord, w, str, 0, beginWord);
        
        return strs;
    }
};