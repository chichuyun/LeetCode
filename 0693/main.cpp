class Solution {
public:
    bool hasAlternatingBits(int n) {
        int count=0, num=n;
        while(num!=0) {
            ++count;
            num >>= 1;
        }

        int flag = n&1;
        for(int i=0;i<count;++i) {
            if(flag!=(n&1)) return false;
            flag = 1 - flag;
            n >>= 1;
        }
        return true;

/*
        n = (n ^ (n>>1));
        return (n & ((long)n+1)) == 0;
*/
    }
};