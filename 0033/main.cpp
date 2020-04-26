class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int left = 0, right = nums.size()-1, mid;
        while(left <= right) {
            mid = left + (right - left)/2;
            if(nums[mid] == target) {
                return mid;
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
        return -1;
    }
};