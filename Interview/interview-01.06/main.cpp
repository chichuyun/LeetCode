class Solution {
public:
    string compressString(string S) {
        if(S.empty()) return S;
        char t;
        int count, i=0;
        ostringstream ss;
        
        while(i<S.size()) {
            t = S[i];
            count = 0;
            while(S[i]==t) {
                ++i;
                ++count;
            }
            ss<<t<<count;
        }

        return ss.str().size()>=S.size() ? S : ss.str();
    }
};