class Solution {

public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int count = 0;
        int i = 0;
        int len = nums.size();
        while(i < len) {
            unordered_set<int> sets = {0};
            int num = 0;
            while(i < len) {
                num += nums[i];
                if(sets.count(num-target)) {
                    ++count;
                    break;
                } else {
                    ++i;
                    sets.insert(num);
                }
            }
            ++i;
        }
        
        return count;
    }
};