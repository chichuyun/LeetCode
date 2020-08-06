class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.empty() || k==0) return 0;
        if(k >= s.size()) return s.size();
        unordered_map<char, int> nums;
        int count = 0, max_v = 0, min_index;
        for(int i=0; i<s.size(); ++i) {
            nums[s[i]] = i;
            if(nums.size() > k) {
                min_index = INT_MAX;
                for(auto p : nums) if(p.second < min_index) min_index = p.second;
                count = i - nums[s[min_index]] - 1;
                nums.erase(s[min_index]);
            }
            
            ++count;
            max_v = max(max_v, count);
        }

        return max_v;
    }
};