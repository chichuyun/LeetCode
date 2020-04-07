class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int i=0, j=nums.size()-1;
        while(nums[j] > target) --j;
        while(i < j) {
            while(nums[i]+nums[j] > target) --j;
            while(nums[i]+nums[j] < target) ++i;
            if(nums[i]+nums[j] == target) {
                res.push_back(nums[i]);
                res.push_back(nums[j]);
                break;
            }
        }
        return res;
    }
};