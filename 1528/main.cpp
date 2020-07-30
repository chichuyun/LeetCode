class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int len = indices.size();
        string strs;
        strs.resize(len);
        
        for(int i=0; i<len; ++i) {
            strs[indices[i]] = s[i];
        }
        
        return strs;
    }
};