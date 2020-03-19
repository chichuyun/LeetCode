class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && num & (num-1) == 0 && (num & 0x55555555) == num;
//        return num > 0 and num & (num - 1) == 0 and num & 0xaaaaaaaa == 0;
    }
};