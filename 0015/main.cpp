#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;

        sort(nums.begin(), nums.end());


        int len = nums.size();
        int l, r, target;
        for(int i=0; i<len; ++i) {
            if(i==0 || nums[i]!=nums[i-1]) {
                l = i + 1;
                r = len - 1;
                while(l < r) { // one element can be only used once!
                    target = nums[i] + nums[l] + nums[r];
                    if(target == 0) {
                        res.push_back({nums[i], nums[l++], nums[r--]});
                        while(r > l && nums[r] == nums[r+1]) --r;
                        while(l < r && nums[l] == nums[l-1]) ++l;
                    } else if(target > 0) {
                        --r;
                    } else {
                        ++l;
                    }
                }
            }
        }
        return res;
    }
};