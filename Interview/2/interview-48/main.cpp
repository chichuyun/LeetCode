class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strs[128];
        memset(strs, -1, 128*sizeof(int));
        int count = 0, cur = 0;
        for(int i=0;i<s.size();++i) {
            char c = s[i];
            if(strs[c]!=-1 && i-strs[c]<=cur) cur = i-strs[c]-1;
            strs[c] = i;
            ++cur;
            count = max(count, cur);
        }
        return count;
    }
};