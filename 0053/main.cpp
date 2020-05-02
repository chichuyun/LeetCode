class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int num = 0, count = INT_MIN;
        for(int n : nums) {
            if(num <= 0) {
                num = n;
            } else {
                num += n;
            }
            count = max(num, count);
        }
        return count;
    }
};