class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        int len = nums.size();
        int left = 0, right = 0;
        while(left < len) {
            while(left < len && nums[left]==0) ++left;
            if(left < len) {
                swap(nums[left], nums[right]);
                ++right;
                ++left;
            }
        }
    }
};