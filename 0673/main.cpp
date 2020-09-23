class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        vector<int> counts(nums.size(),1);
        vector<int> counts_s(nums.size(),1);
        vector<int> mems(nums.size()+1,0);
        for(int i=0; i<nums.size(); ++i) {
            int j = i-1, maxCount = 0, count = 1;
            while(j >= 0) {
                if(nums[j] < nums[i]) {
                    if(counts[j] > maxCount) {
                        count = counts_s[j];
                        maxCount = counts[j];
                    } else if(counts[j] == maxCount) {
                        count += counts_s[j];
                    }
                }
                --j;
            }
            counts[i] = maxCount + 1;
            counts_s[i] = count;
            mems[maxCount+1] += count;
        }

        for(int i=(int)nums.size(); i>=0; --i) {
            if(mems[i] != 0) return mems[i];
        }

        return 0;
    }
};