class Solution {
private:
    bool backtrace(string& s, int n, string& p, int m) {
        if(m==p.size()) return n==s.size() ? true : false;

        bool first = n != s.size() && (p[m] == s[n] || p[m] == '.');

        if(m+1 < p.size() && p[m+1]=='*') {
            return backtrace(s, n, p, m+2) ||             // 0
                   (first && backtrace(s, n+1, p, m));    // 1 or more
        } else {
            return first && backtrace(s, n+1, p, m+1);    // next
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        if(backtrace(s, 0, p, 0)) return true;
        return false;
    }
};