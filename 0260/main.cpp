class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num=0, a=0;
        for(int n : nums) num ^= n;
        int mask = num & (~num + 1);  // mask = num & -num  // lowbit
        for(int n : nums) if(n&mask) a ^= n;
        return {a, num^a};
    }
};