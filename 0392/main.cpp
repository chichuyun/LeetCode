class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        int k = 0, len_s = s.size();
        for(char& ss : t) {
            if(ss==s[k]) ++k;
            if(k==len_s) return true;
        }
        return false;
    }
};