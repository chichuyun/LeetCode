class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        } else if(nums.size()==1) {
            return nums[0];
        }
        
        nums[1] = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();++i) {
            nums[i] = max(nums[i-1],nums[i-2]+nums[i]);
        }

        return nums[nums.size()-1];
    }
};