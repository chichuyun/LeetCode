class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> strs;
        if(nums.empty()) return strs;
        int count = 1, len = nums.size();

        for(int i=1;i<len;++i) {
            if((long)nums[i]-nums[i-1]!=1) {
                if(count==1) {
                    strs.push_back(to_string(nums[i-1]));
                } else {
                    strs.push_back(to_string(nums[i-count])+"->"+to_string(nums[i-1]));
                }
                count = 0;
            }
            ++count;
        }
        if(count==1) {
            strs.push_back(to_string(nums[len-1]));
        } else {
            strs.push_back(to_string(nums[len-count])+"->"+to_string(nums[len-1]));
        }        
        return strs;
    }
};