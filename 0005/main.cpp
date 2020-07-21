class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));
        for(int i=0; i<s.size(); ++i) {
            dp[i][i] = true;
        }
        
        int maxLen = 1, k = 0;
        for(int j=0; j<dp.size(); ++j) {
            for(int i=0; i<j; ++i) {
                if(s[i]!=s[j]) {
                    dp[i][j] = false;
                } else if(j - i < 3) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i+1][j-1];
                }

                if(dp[i][j] && j-i+1 > maxLen) {
                    k = i;
                    maxLen = j - i + 1;
                }
            }
        }
        
        return s.substr(k, maxLen);
    }
};