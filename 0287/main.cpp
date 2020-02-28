class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left, mid, right, count;
        left = 1;
        right = nums.size()-1;
        while(left < right) {
            mid = left + (right - left)/2;
            count = 0;
            for(int i=0;i<nums.size();++i) {
                if(mid>=nums[i]) count++;
            }
            if(mid<count) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};