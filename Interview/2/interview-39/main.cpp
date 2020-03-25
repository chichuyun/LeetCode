class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int num = nums[0], count=0;
        for(int i=1;i<nums.size();++i) {
            if(num==nums[i]) {
                ++count;
            } else if(count) {
                --count;
            } else {
                num = nums[i];
            }
        }
        return num;
    }
};