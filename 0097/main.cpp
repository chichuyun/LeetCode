class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<bool>> dp(s1.size()+1,vector<bool>(s2.size()+1));
        dp[0][0] = true;
        for(int i=1;i<=s1.size();++i) dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        for(int j=1;j<=s2.size();++j) dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        for(int i=1;i<=s1.size();++i) {
            for(int j=1;j<=s2.size();++j) {
                dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1] ||
                           dp[i][j-1] && s2[j-1] == s3[i+j-1];
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

/* time out
class Solution {
private:
    bool helper(string& s1, string& s2, string& s3, int i, int j, int k) {
        if(i==s1.size() && j==s2.size()) {
            return true;
        } else if((i==s1.size() || s1[i]!=s3[k]) && s2[j]==s3[k]) {
            return helper(s1, s2, s3, i, j+1, k+1);
        } else if((j==s2.size() || s2[j]!=s3[k]) && s1[i]==s3[k]) {
            return helper(s1, s2, s3, i+1, j, k+1);
        } else if(i<s1.size() && j<s2.size()) {
            if(s1[i]==s3[k] && s2[j]==s3[k]) {
                return helper(s1, s2, s3, i, j+1, k+1) ||
                       helper(s1, s2, s3, i+1, j, k+1);
            }
        }
        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        return helper(s1, s2, s3, 0, 0, 0);
    }
};
*/