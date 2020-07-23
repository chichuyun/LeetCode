class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(abs((int)s.size() - (int)t.size()) > 1 || s == t) return false;
        
        if(s.size() > t.size()) {
            string f = s;
            s = t;
            t = f;
        }

        if(s.empty() && t.size()==1) return true;
        
        int len = s.size();

        int count = 0;
        for(int i=0; i<len; ++i) {
            if(s[i] != t[i]) ++count;
        }
        if(len == t.size() && count == 1) return true;
        if(len != t.size() && count == 0) return true;
        for(int i=0; i<s.size(); ++i) {
            if(s[i]!=t[i]) {
                t.erase(i,1);
                break;
            }
        }
        return s == t;
    }
};