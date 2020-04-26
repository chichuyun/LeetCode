class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0, diff = 0;
        for(int i=0;i<4;++i) {
            if(nums[i]==0) {
                ++count;
            } else if(nums[i+1]-nums[i]==0) {
                return false;
            } else {
                diff += nums[i+1] - nums[i] - 1;
            }
        }
        if(diff<=count) return true;
        return false;
    }
};