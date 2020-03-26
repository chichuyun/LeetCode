class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0, b=0;
        for(int n : nums) {
            b = ~a & (b ^ n);
            a = ~b & (a ^ n);
        }
        return b;
    }
};