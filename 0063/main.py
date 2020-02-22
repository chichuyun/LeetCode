class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        n = len(obstacleGrid)
        m = len(obstacleGrid[0])

        dp = [[0]*m for i in range(n)]

        for j in range(n):
            if obstacleGrid[j][0] == 1: break
            dp[j][0] = 1
        for i in range(m):
            if obstacleGrid[0][i] == 1: break
            dp[0][i] = 1
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[j][i] == 1: continue
                dp[j][i] = dp[j-1][i] + dp[j][i-1]

        return dp[n-1][m-1]
