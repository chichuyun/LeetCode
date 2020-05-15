class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int count = 0, num;
        for(int i=0;i<len;++i) {
            num = 0;
            for(int j=i;j<len;++j) {
                num += nums[j];
                if(num == k) count++;
            }
        }
        return count;
    }
};