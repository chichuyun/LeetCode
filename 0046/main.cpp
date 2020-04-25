class Solution {
private:
    vector<vector<int>> res;
    void helper(vector<int> nums, int n) {
        if(n == nums.size()-1) return;
        helper(nums, n+1);
        for(int i=n+1;i<nums.size();++i) {
            res.push_back(nums);
            swap(res.back()[n], res.back()[i]);
            helper(res.back(), n+1);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.push_back(nums);
        if(nums.empty()) return res;
        helper(nums, 0);
        return res;
    }
};