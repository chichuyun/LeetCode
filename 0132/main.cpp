class Solution {
public:
    int minCut(string s) {
        if(s.empty()) return 0;
        int len = s.size();

        vector<vector<bool>> checks(len, vector<bool>(len, false));
        for(int i=0; i<len; ++i) checks[i][i] = true;
        for(int i=len-1; i>=0; --i) {  // s[i..j] is true?
            for(int j=i; j<len; ++j) {
                if(s[i]==s[j]) {
                    if(j - i < 3) {
                        checks[i][j] = true;
                    } else {
                        checks[i][j] = checks[i+1][j-1];
                    }
                }
            }
        }

        vector<int> dp(len+1);
        for(int i=1; i<=len; ++i) dp[i] = i;
        dp[0] = -1;
        for(int i=0; i<len; ++i) {
            for(int j=0; j<=i; ++j) {
                if(checks[j][i]) {
                    dp[i+1] = min(dp[i+1], dp[j]+1);
                }
            }
        }

        return dp[len];
    }
};