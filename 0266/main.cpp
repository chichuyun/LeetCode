class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> nums;
        for(auto& ss : s) ++nums[ss];

        int count = 0;
        for(auto& p : nums) {
            if(p.second%2) {
                ++count;
            }
        }

        if(s.size()%2 && count==1) return true;
        if(s.size()%2==0 && count==0) return true;

        return false;
    }
};