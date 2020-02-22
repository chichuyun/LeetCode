class Solution {
public:
    vector<int> nums0;
    Solution(vector<int>& nums) {
        nums0 = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums0;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums = nums0;
        random_shuffle(nums.begin(),nums.end());
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */