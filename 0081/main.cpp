class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int left = 0, right = nums.size()-1, mid;
        while(right > 0 && nums[right]==nums[0]) --right;
        while(left <= right) {
            while(left+1 <= right && nums[left]==nums[left+1]) ++left;
            while(right > left && nums[right]==nums[right-1]) --right;
            mid = left + (right - left)/2;
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] > target) {
                if(target >= nums[0]) {
                    right = mid - 1;
                } else if(nums[mid] >= nums[0]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if(target < nums[0]) {
                    left = mid + 1;
                } else if(nums[mid] < nums[0]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};