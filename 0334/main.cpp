class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<=2) return false;
        
        int left=0x7fffffff, mid=0x7fffffff;
        for(int i=0;i<nums.size()-1;++i) {
            if(nums[i+1]<mid) {
                if(nums[i]<nums[i+1]) {
                    left = nums[i];
                    mid = nums[i+1];
                } else if(nums[i+1]>left) {
                    mid = nums[i+1];
                }
            } else if(nums[i+1]>mid) {
                return true;
            }
        }
        return false;
/*
        int m1 = INT_MAX, m2 = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= m1) m1 = nums[i];
            else if(nums[i] <= m2) m2 = nums[i];
            else return true;
        }
         return false;  
*/
    }
};