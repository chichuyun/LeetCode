class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lst;
        for(int i=0;i<nums.size();++i) {
            if(lst.empty() || lst.back()<nums[i]) {
                lst.push_back(nums[i]);
            } else {
                int j;
                for(j=0;j<lst.size() && lst[j]<nums[i];++j);
                if(lst[j]>=nums[i]) lst[j] = nums[i];
            }
        }
        return lst.size();
    }
};