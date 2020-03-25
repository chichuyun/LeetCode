class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0], count=nums[0];
        
        for(int i=1;i<nums.size();++i) {
            if(count>0) {
                count += nums[i];
            } else {
                count = nums[i];
            }
            res = max(count,res);
        }
        return res;
    }
};