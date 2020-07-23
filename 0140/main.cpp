#include<unordered_set>

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;
        for(int i=0; i<wordDict.size(); ++i) {
            wordDictSet.insert(wordDict[i]);
        }

        vector<bool> check(s.size()+1, false);
        check[0] = true;

        vector<string> strs;
        for(int i=1; i<=s.size(); ++i) {
            for(int j=0; j<i; ++j) {
                if(check[j] && wordDictSet.count(s.substr(j,i-j))!=0) {
                    check[i] = true;
                    break;
                }
            }
        }

        if(!check[s.size()]) return strs;

        vector<vector<string>> dp(s.size()+1);
        dp[0].push_back("");

        for(int i=1; i<=s.size(); ++i) {
            for(int j=0; j<i; ++j) {
                if(dp[j].size()!=0 && wordDictSet.count(s.substr(j,i-j))!=0) {
                    if(j==0) {
                        dp[i].push_back(s.substr(j,i-j));
                    } else {
                        for(auto& str : dp[j]) {
                            dp[i].push_back(str + " " + s.substr(j,i-j));
                        }
                    }
                }
            }
        }

        return dp[s.size()];
    }
};