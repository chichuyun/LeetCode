class Solution {
public:
    int getSum(int a, int b) {
        int res=0;
        while(b != 0) {
            res = a ^ b;
            b = (unsigned int)(a & b) << 1;
            a = res;
        }
        return res;
    }
};