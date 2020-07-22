class Solution {
private:
    vector<vector<int>> res;
    void helper(vector<int>& candidates, int k, int target, vector<int> nums) {
        if(target == 0) {
            res.push_back(nums);
            return;
        }
        if(k==candidates.size()) return;

        while(target >= 0) {
            helper(candidates, k+1, target, nums);
            target -= candidates[k];
            nums.push_back(candidates[k]);
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, {});
        return res;
    }
};