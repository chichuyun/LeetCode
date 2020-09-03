class Solution {
public:
    void reverseWords(vector<char>& s) {
        int left = 0, right = s.size()-1;
        while(left < right) {
            char s_l = s[left];
            s[left] = s[right];
            s[right] = s_l;
            ++left;
            --right;
        }
        left = 0, right = 0;
        while(left < s.size()) {
            while(right < s.size() && s[right] != ' ') ++right;
            if(right == s.size() - 1) ++right;
            int l = left, r = right - 1;
            while(l < r) {
                char s_l = s[l];
                s[l] = s[r];
                s[r] = s_l;
                ++l;
                --r;
            }
            ++right;
            left = right;
        }
    }
};