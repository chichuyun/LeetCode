class Solution {
public:
    int titleToNumber(string s) {
        int num=0, base=1;

        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();++i) {
            num += pow(26,i)*(s[i]-64);
        }
        return num;
    }
};