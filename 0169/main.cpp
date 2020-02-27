class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1, major;

        major = nums[0];
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==major) {
                count++;
            } else {
                count--;
                if(count==0) major = nums[i+1];
            }
        }
        return major;
    }
};