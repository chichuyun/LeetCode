class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& factors, int k, int n, vector<int> nums) {
        if(n==1) {
            res.push_back(nums);
            return;
        }
        if(k==factors.size()) return;
        dfs(factors, k+1, n, nums);
        int factor = factors[k];
        int mod = n%factor;
        while(!mod) {
            nums.push_back(factor);
            n /= factor;
            dfs(factors, k+1, n, nums);
            mod = n%factor;
        }
    }
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> factors;
        for(int i=2; 2*i<=n; ++i) {
            if(n%i==0) factors.push_back(i);
        }

        if(factors.empty()) return {};
        dfs(factors, 0, n, {});
        return res;
    }
};