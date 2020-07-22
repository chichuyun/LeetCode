class Solution {
private:
    vector<vector<bool>> checks;
    vector<vector<string>> strs;
    
    void dfs(string& s, int k, vector<string>& temp) {
        if(k == s.size()) {
            strs.push_back(temp);
            return;
        }
        for(int i=k; i<s.size(); ++i) {
            if(checks[k][i]) {
                temp.push_back(s.substr(k, i-k+1));
                dfs(s, i+1, temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) return strs;
        int len = s.size();
        checks.resize(len, vector<bool>(len, false));
        for(int i=0; i<len; ++i) checks[i][i] = true;

        for(int i=len-1; i>=0; --i) {  // s[i..j] is true?
            for(int j=i; j<len; ++j) {
                if(s[i]==s[j]) {
                    if(j - i < 3) {
                        checks[i][j] = true;
                    } else {
                        checks[i][j] = checks[i+1][j-1];
                    }
                }
            }
        }

        vector<string> temp;
        dfs(s, 0, temp);

        return strs;
    }
};