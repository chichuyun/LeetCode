class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> strs;
        if(s.size()<10) return strs;
        unordered_map<string,int> nums;
        for(int i=0;i<=s.size()-10;++i) {
            ++nums[s.substr(i,10)];
        }
        for(auto str : nums) {
            if(str.second > 1) strs.push_back(str.first);
        }
        return strs;
    }
};