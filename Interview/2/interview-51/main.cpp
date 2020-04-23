class Solution {
private:
    vector<int> merge(vector<int>& nums, int i, int j, int& count) {
        if(i == j) return {nums[i]};
        int k = (i + j)/2;
        vector<int> left = merge(nums, i, k, count);
        vector<int> right = merge(nums, k+1, j, count);
        int m = 0, n = 0, len = left.size();
        vector<int> ans;
        while(m<left.size() && n<right.size()) {
            if(left[m]<=right[n]) {
                ans.push_back(left[m]);
                ++m;
            } else {
                ans.push_back(right[n]);
                ++n;
                count += len - m;
            }
        }
        while(m<left.size()) {
            ans.push_back(left[m]);
            ++m;
        }
        while(n<right.size()) {
            ans.push_back(right[n]);
            ++n;
        }
        return ans;
    }
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        merge(nums, 0, nums.size()-1, count);
        return count;
    }
};