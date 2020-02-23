class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counts=0;
        for(int i=0;i<32;i++) {
            if(n%2==1) {
                counts++;
            }
            n =  n >> 1;
        }
        return counts;
/*
        return bitset<32>(n).count();
*/
    }
};