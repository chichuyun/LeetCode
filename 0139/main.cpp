#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;

        for(auto& p : wordDict) wordDictSet.insert(p);
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i=1; i<=s.size(); ++i) {  // dp loop
            for(int j=0; j<i; ++j) {
                if(dp[j] && wordDictSet.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};