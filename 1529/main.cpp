class Solution {
public:
    int minFlips(string target) {
        if(target.empty()) return 0;
        int count = 0;
        int len = target.size();
        
        char c;
        if(target[len-1]=='0') {
            c = '1';
        } else {
            c = '0';
        }
        for(int i=len-1; i>=0; --i) {
            if(target[i]!=c) {
                c = target[i];
                ++count;
            }
        }
        
        
        if(target[0]=='0' && count > 0) --count;
        return count;
    }
};