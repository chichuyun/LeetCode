class Solution {
public:
    char firstUniqChar(string s) {
        int strs[128];
        memset(strs, 0, sizeof(int)*128);
        for(char c : s) {
            ++strs[c];
        }
        for(char c : s) {
            if(strs[c]==1) return c;
        }
        return ' ';
    }
};