class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        int len = s.size();
        for(int i=0; i<len-1; ++i) {
            if(s[i]=='+' && s[i+1]=='+') {
                s[i] = '-';
                s[i+1] = '-';
                res.push_back(s);
                s[i] = '+';
                s[i+1] = '+';
            }
        }
        return res;
    }
};