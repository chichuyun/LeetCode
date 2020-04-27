class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<int>> dp(n+1, vector<int>(6*n+1,0));
        vector<double> nums(5*n+1);
        double base = 1.0/pow(6.0,n);
        for(int i=1;i<=6;++i) dp[1][i] = 1; // n = 1
        for(int j=2;j<=n;++j) {
            for(int k=j;k<=6*j;++k) {
                int lower = max(j-1, k-6);  // [j-1, 6*(j-1)]
                int upper = min(6*j-6, k-1);
                for(int i=lower;i<=upper;++i) {
                    dp[j][k] += dp[j-1][i];
                }
            }
        }
        for(int j=0;j<=5*n;++j) {
            nums[j] = dp[n][j+n]*base;
        }
        return nums;
    }
};