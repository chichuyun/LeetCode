class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> sets;
        
        for(int i=0;i<nums.size();++i) {
            auto n = sets.lower_bound((long)nums[i] - t);  // >= nums[i] - t
            if(n != sets.end() && *n <= (long)nums[i] + t) return true;  // <= nums[i] + t

            sets.insert(nums[i]);
            if(sets.size() > k) {
                sets.erase(nums[i-k]);
            }
        }
        return false;
    }
};