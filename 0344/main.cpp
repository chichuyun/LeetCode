class Solution {
public:
    // recursion
    void reverseString(vector<char>& s) {
        swap(s, 0, s.size()-1);
    }
    void swap(vector<char>& s, int left, int right) {
        if(right-left<1)
            return;
        char c;
        c = s[right];
        s[right] = s[left];
        s[left] = c;
        swap(s,++left,--right);
    }
};