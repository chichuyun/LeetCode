class Solution {
private:
    void helper(vector<vector<int>>& nums, int& count, int& k, int n, int m) {
        if(m > k) return;
        if(n == nums.size()-1 && m==k) ++count;
        for(int i=0;i<nums[n].size();++i) {
            helper(nums, count, k, nums[n][i], m+1);
        }
    }
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> nums(n);
        for(auto p : relation) {
            nums[p[0]].push_back(p[1]);
        }
        int count = 0;
        for(int i=0;i<nums[0].size();++i) {
            helper(nums, count, k, nums[0][i], 1);
        }
        return count;
    }
};