class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size(), cols = grid[0].size();
        vector<int> dp(cols), dp2(cols);
        dp[0] = grid[0][0];
        for(int i=1; i<cols; ++i) dp[i] = dp[i-1] + grid[0][i];  // first rows

        for(int i=1; i<rows; ++i) {
            for(int j=0; j<cols; ++j) dp2[j] = dp[j];
            dp[0] = dp2[0] + grid[i][0];  // first cols
            for(int j=1; j<cols; ++j) {
                dp[j] = min(dp[j-1], dp2[j]) + grid[i][j];
            }
        }

        return dp[cols-1];
    }
};