class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.empty() && grid[0].empty()) return 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows+1, vector<int>(cols+1,0));
        for(int i=1;i<=rows;++i) {
            for(int j=1;j<=cols;++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
            }
        }
        return dp[rows][cols];
    }
};