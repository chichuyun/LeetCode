class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num=0, a=0, b=0;
        for(int n : nums) num ^= n;
        int mask = num & (~num + 1);
        for(int n : nums) {
            if(n&mask) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        return {a, b};
    }
};