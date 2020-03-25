class Solution {
public:
    int add(int a, int b) {
        while(b != 0) {
            int temp = a ^ b;
            b = (unsigned int)(a & b) << 1;
            a = temp;
        }
        return a;
    }
};