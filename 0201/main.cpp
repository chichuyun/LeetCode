class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count=0;
        while(m!=n) {
            n >>= 1;
            m >>= 1;
            ++count;
        }
        n <<= count;
        return n;
/*
        while (n > m) n &= (n - 1);
        return n;
*/
    }
};