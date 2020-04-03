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