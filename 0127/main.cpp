#include<unordered_map>
#include<string>
#include<vector>
#include<queue>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> words;
        for(string& s : wordList) {
            words[s] = false;
        }

        unordered_map<string, vector<string>> wordMap;
        int len = beginWord.size();
        for(string& s : wordList) {
            for(int i=0; i<len; ++i) {
                wordMap[s.substr(0,i)+"*"+s.substr(i+1,len-i-1)].push_back(s);
            }
        }

        queue<string> strs;
        strs.push(beginWord);
        int count = 1, num = 1;
        while(!strs.empty()) {
            ++count;
            while(num--) {
                string str = strs.front();
                strs.pop();

                for(int i=0; i<len; ++i) {
                    string mode = str.substr(0,i)+"*"+str.substr(i+1,len-i-1);
                    if(wordMap.count(mode)) {
                        for(string& s : wordMap[mode]) {
                            if(str!=s && !words[s]) {
                                if(s == endWord) return count;
                                strs.push(s);
                                words[s] = true;
                            }
                        }
                    }
                }
            }
            num = strs.size();
        }

        return 0;
    }
};