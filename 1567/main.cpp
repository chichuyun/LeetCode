class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        int i = 0, j = 0;
        int len = nums.size();
        while(i < len) {
            j = i;
            count = 0;
            while(j < len && nums[j] != 0) {
                if(nums[j] < 0) ++count;
                ++j;
            }
            if(i!=j) {
                if(count%2 == 0) {
                    maxCount = max(maxCount, j-i);
                } else {
                    int l = i;
                    int r = j-1;
                    while(nums[l] > 0) ++l;
                    while(nums[r] > 0) --r;
                    maxCount = max(maxCount, max(r-i, j-l-1));
                }
            }
            i = j + 1;
        }
        
        return maxCount;
    }
};