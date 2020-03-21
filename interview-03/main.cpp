class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int n : nums) {
            if(nums[abs(n)]<0) {
                return abs(n);
            } else {
                nums[abs(n)] = -nums[abs(n)];
            }
        }
        return 0;
    }
};