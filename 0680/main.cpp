class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1, len = s.size();
        while(l < len && r >=0 && l!=r && s[l] == s[r]) { --r; ++l; }
        if(r <= l) return true;
        int l1 = l+1, r1 = r;
        while(l1 < len && r1 >=0 && l1!=r1 && s[l1] == s[r1]) { --r1; ++l1; }
        if(r1 <= l1) return true;
        int l2 = l, r2 = r-1;
        while(l2 < len && r2 >=0 && l2!=r2 && s[l2] == s[r2]) { --r2; ++l2; }
        if(r2 <= l2) return true;

        return false;
    }
};