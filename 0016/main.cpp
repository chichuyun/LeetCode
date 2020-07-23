class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX, count = INT_MAX;

        sort(nums.begin(), nums.end());

        int l, r, s, len = nums.size();
        for(int i=0; i<len; ++i) {
            l = i + 1;
            r = len - 1;
            while(l < r) {
                s = nums[i] + nums[l] + nums[r];
                if(s == target) {
                    return target;
                } else if(s > target) {  // 0 <<--
                    if(s - target < count) {
                        count = s - target;
                        res = s;
                    }
                    --r;
                } else {
                    if(target - s < count) {  // -->> 0
                        count = target - s;
                        res = s;
                    }
                    ++l;
                }
            }
        }

        return res;
    }
};