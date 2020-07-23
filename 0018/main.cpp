class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        sort(nums.begin(), nums.end());

        int l, r, s, len = nums.size();
        for(int i=0; i<len; ++i) {
            if(i==0 || nums[i]!=nums[i-1]) {
                for(int j=i+1; j<len; ++j) {
                    if(j==i+1 || nums[j]!=nums[j-1]) {
                        l = j + 1;
                        r = len - 1;
                        while(l < r) {
                            s = nums[i] + nums[j] + nums[l] + nums[r];
                            if(s == target) {
                                res.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                                while(r > l && nums[r]==nums[r+1]) --r;
                                while(l < r && nums[l]==nums[l-1]) ++l;
                            } else if(s > target) {
                                --r;
                            } else {
                                ++l;
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};