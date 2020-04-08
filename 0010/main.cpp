class Solution {
private:
    vector<vector<int>> nums;

    bool backtrace(string& s, int n, string& p, int m) {
        if(m==p.size()) return n==s.size() ? true : false;
        
        if(nums[n][m]) return false;
        bool flag = n != s.size() && (p[m] == s[n] || p[m] == '.');

        if(m+1 < p.size() && p[m+1]=='*') {
            flag = backtrace(s, n, p, m+2) ||             // 0
                   (flag && backtrace(s, n+1, p, m));    // 1 or more
        } else {
            flag = flag && backtrace(s, n+1, p, m+1);    // next
        }
        nums[n][m] = 1;
        return flag;
    }
public:
    bool isMatch(string s, string p) {
        nums.resize(s.size()+1,vector<int>(p.size()+1,0));
        if(backtrace(s, 0, p, 0)) return true;
        return false;
    }
};

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[s.size()][p.size()] = true;
        for(int i=s.size();i>=0;--i) {
            for(int j=p.size()-1;j>=0;--j) {
                bool first = i < s.size() && (s[i] == p[j] || p[j] == '.');  // null or equal
                if(j+1<p.size() && p[j+1]=='*') {
                    dp[i][j] = (first && dp[i+1][j]) || dp[i][j+2];  // 0 or more
                } else {
                    dp[i][j] = first && dp[i+1][j+1];  // next
                }
            }
        }
        return dp[0][0];
    }
};
*/