class Solution {
private:
    bool isPalindrome(string& s, string& t) {
        int len_s = s.size(), len_t = t.size();
        int l = 0, r = len_s + len_t - 1;
        char cl, cr;
        while(l < r) {
            if(l < len_s) {
                cl = s[l];
            } else {
                cl = t[l-len_s];
            }

            if(r >= len_s) {
                cr = t[r-len_s];
            } else {
                cr = s[r];
            }
            
            l++;
            r--;
            if(cl != cr) return false;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> nums;

        if(words.empty()) return nums;
        string s;
        for(int i=0; i<words.size(); ++i) {
            for(int j=i+1; j<words.size(); ++j) {
                if(isPalindrome(words[i], words[j])) nums.push_back({i, j});
                if(isPalindrome(words[j], words[i])) nums.push_back({j, i});
            }
        }
        return nums;
    }
};