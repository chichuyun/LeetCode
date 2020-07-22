class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty()) return 0;

        int len = costs.size();
        vector<vector<int>> dp(len+1, vector<int>(3, 0));

        for(int i=1; i<=len; ++i) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i-1][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i-1][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i-1][2];
        }

        return min(dp[len][0], min(dp[len][1], dp[len][2]));
    }
};