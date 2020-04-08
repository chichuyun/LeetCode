class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, imax = 1, imin = 1;
        for(int i=0;i<nums.size();++i) {
            if(nums[i] < 0) swap(imax, imin);
            imax = max(imax*nums[i], nums[i]);
            imin = min(imin*nums[i], nums[i]);
            res = max(res, imax);
        }
        return res;
    }
};