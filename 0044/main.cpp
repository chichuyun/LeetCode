class Solution {
private:
    vector<vector<int>> nums;

    bool helper(string& s, int m, string& p, int n) {
        if(n==p.size()) {
            if(m==s.size()) {
                return true;
            } else {
                return false;
            }
        }
        
        if(nums[m][n]) return false;
        bool flag;
        if(m != s.size()) {
            if(p[n] != '*') {
                if(p[n] == s[m] || p[n] == '?') {
                    flag = helper(s, m+1, p, n+1);  // next
                } else {
                    flag = false;
                }
            } else {
                while(n < p.size() && p[n]=='*') ++n;
                --n;
                flag = helper(s, m, p, n+1) || helper(s, m+1, p, n);  // 0 or more
            }
        } else {
            if(p[n] == '*') {
                while(n < p.size() && p[n]=='*') ++n;
                --n;
                flag = helper(s, m, p, n+1);
            } else {
                flag = false;
            }
        }
        nums[m][n] = 1;
        return flag;
    }

public:
    bool isMatch(string s, string p) {
        nums.resize(s.size()+1,vector<int>(p.size()+1,0));
        return helper(s, 0, p, 0);
    }
};