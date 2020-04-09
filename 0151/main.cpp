class Solution {
public:
    string reverseWords(string s) {
        ostringstream str, res;
        int i = 0;
        while(i<s.size() && s[i]==' ') ++i;
        if(i==s.size()) return res.str();
        reverse(s.begin(),s.end());
        s.push_back(' ');
        for(int j=0;j<s.size();++j) {
            if(s[j]!=' ') {
                str<<s[j];
            } else {
                if(!str.str().empty()) {
                    string ss = str.str();
                    reverse(ss.begin(),ss.end());
                    res<<ss<<' ';
                    str.str("");
                }
            }
        }
        string ss = res.str();
        ss.pop_back();
        return ss;
    }
};