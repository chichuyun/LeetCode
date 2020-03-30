class Solution {
public:
    string reverseStr(string s, int k) {
        if(k<1) return s;
        int len = s.size();
        for(int i=0;i<len;i+=k+k) {
            int j = i;
            int n = i + min(k,len-i) - 1;
            while(j < n) {
                swap(s[j], s[n]);
                --n; ++j;
            }
        }
        return s;
    }
};