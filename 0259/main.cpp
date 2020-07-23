class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        if(nums.size() < 3) return count;
        sort(nums.begin(), nums.end());

        int s, l, r, len = nums.size();
        for(int i=0; i<len; ++i) {
            l = i + 1;
            r = len - 1;
            while(l < r) {
                s = nums[i] + nums[l] + nums[r];
                if(s < target) {
                    count += r - l;
                    ++l;
                } else {
                    --r;
                }
            }
        }

        return count;
    }
};