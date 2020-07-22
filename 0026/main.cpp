class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();

        int left = 0;
        int right = 1;
        int len = nums.size();
        while(right < len) {
            while(right < len && nums[left] == nums[right]) ++right;
            
            if(right < len) {
                ++left;
                nums[left] = nums[right];
            }
            ++right;
        }
        
        return left+1;
    }
};