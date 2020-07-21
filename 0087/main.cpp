#include<string>
#include<algorithm>

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;

        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if(t1 != t2) return false;

        int len = s1.size(); 
        for(int i=1; i<len; ++i) {  // must start from 1
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && 
               isScramble(s1.substr(i,len-i), s2.substr(i,len-i))) return true;
            if(isScramble(s1.substr(0,i), s2.substr(len-i,i)) && 
               isScramble(s1.substr(i,len-i), s2.substr(0,len-i))) return true;
        }

        return false;
    }
};