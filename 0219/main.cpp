class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> maps;

        for(int i=0; i<nums.size(); ++i) {
            int& n = nums[i];
            if(maps.count(n)) {
                if(i - maps[n] <= k) {
                    return true;
                } else {
                    maps[n] = i;
                }
            } else {
                maps[n] = i;
            }
        }

        return false;
    }
};