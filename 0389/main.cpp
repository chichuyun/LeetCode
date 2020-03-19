class Solution {
public:
    char findTheDifference(string s, string t) {
        char str=0;
        for(char c : s) str ^= c;
        for(char c : t) str ^= c;
        return str;
    }
};