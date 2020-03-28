class Solution {
public:
    int findComplement(int num) {
        int mask = 0x80000000;
        num = ~num;
        int count = 0;
        while(num & mask) {
            ++count;
            num = (unsigned int)num << 1;
        }
        num >>= count;
        return num;
    }
};