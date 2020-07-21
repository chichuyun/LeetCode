class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty() || dungeon[0].empty()) return 0;
        
        int rows = dungeon.size(), cols = dungeon[0].size();
        vector<vector<int>> dp(rows, vector(cols, 0));
        
        dp[rows-1][cols-1] = max(1-dungeon[rows-1][cols-1], 1);
        for(int i=rows-2; i>=0; --i) dp[i][cols-1] = max(dp[i+1][cols-1]-dungeon[i][cols-1], 1);
        for(int j=cols-2; j>=0; --j) dp[rows-1][j] = max(dp[rows-1][j+1]-dungeon[rows-1][j], 1);

        for(int i=rows-2; i>=0; --i) {
            for(int j=cols-2; j>=0; --j) {
                dp[i][j] = max(min(dp[i+1][j], dp[i][j+1])-dungeon[i][j], 1);
            }
        }

        return dp[0][0];
    }
};