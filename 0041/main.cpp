class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0) return 1;

        int max=nums.size(), flag=0;
        for(int i=0;i<max;++i) {
            if(nums[i]==max) flag = 1;
            if(nums[i]>max || nums[i]<=0) nums[i] = max;
        }
        for(int i=0;i<max;++i) {
            if(nums[abs(nums[i])-1]>0) {
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            }
        }
        for(int i=0;i<max;++i) {
            if(nums[i]>0) {
                return i+1;
            }
        }
        
        if(flag) {
            return max+1;
        } else {
            return max;
        }
    }
};