class Solution {
public:
    int calculate(string s) {
        int x = 1, y = 0;
        for(int i=0; i<s.size(); ++i) {
            if(s[i]=='A') {
                x = 2*x + y;
            } else {
                y = 2*y + x;
            }
        }
        return x+y;
    }
};