class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty() || nums.size()==1) return true;
        int num = nums[0];
        for(int n : nums) {
            if(num <= 0) {
                return false;
            } else {
                num = max(--num, n);
            }
        }
        return true;
    }
};