#include<unordered_set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> arrays;
        for(int& n : nums) arrays.insert(n);

        int max_v = 0;
        for(int n : arrays) {
            if(arrays.count(n-1)==0) {
                int c = n;
                int count = 0;
                 
                while(arrays.count(n)) {
                    ++count;
                    ++n;
                }

                max_v = max_v > count ? max_v : count;
            }
        }
        
        return max_v;
    }
};