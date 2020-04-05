class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> nums;
        for(char s : magazine) ++nums[s];
        for(char s : ransomNote) {
            if(nums[s]==0) return false;
            --nums[s];
        }
        return true;
    }
};