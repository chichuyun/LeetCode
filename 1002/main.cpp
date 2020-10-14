class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int len = A.size();
        vector<vector<int>> counts(len, vector<int>(26,0));

        for(int i=0; i<len; ++i) {
            for(char& c : A[i]) {
                counts[i][c-'a']++;
            }
        }

        vector<string> res;
        int count;
        for(int j=0; j<26; ++j) {
            count = INT_MAX;
            for(int i=0; i<len; ++i) {
                count = min(count, counts[i][j]);
            }
            for(int i=0; i<count; ++i) {
                string s;
                s.push_back(char(j+'a'));
                res.push_back(s);
            }
        }
        
        return res;
    }
};