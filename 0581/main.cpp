class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int l = 0, r = 0;
        for(int i=0;i<nums.size()-1;++i) {
            if(nums[i]>nums[i+1]) {
                l = i;
                break;
            }
        }

        for(int i=nums.size()-1;i>0;--i) {
            if(nums[i]<nums[i-1]) {
                r = i;
                break;
            }
        }
        if(l == r) return 0;  // l and r are initial value.
        int max_v = INT_MIN, min_v = INT_MAX;

        // find max and min element of nums
        for(int i=l;i<=r;++i) {
            if(nums[i] > max_v) max_v = nums[i];
            if(nums[i] < min_v) min_v = nums[i];
        }

        // find left bound
        for(int i=0;i<l;++i) {
            if(nums[i] > min_v) {
                l = i;
                break;
            }
        }
        // find right bound
        for(int i=nums.size()-1;i>r;--i) {
            if(nums[i] < max_v) {
                r = i;
                break;
            }
        }
        return r-l+1;
    }
};