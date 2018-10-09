class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        m = len(grid[0])
        
        dp = grid.copy()
        for i in range(1,m):
            dp[0][i] = dp[0][i] + dp[0][i-1]
        for j in range(1,n):
            dp[j][0] = dp[j][0] + dp[j-1][0]
    
        for i in range(1,m):
            for j in range(1,n):
                dp[j][i] = min(dp[j-1][i], dp[j][i-1]) + dp[j][i]

        return dp[n-1][m-1]
