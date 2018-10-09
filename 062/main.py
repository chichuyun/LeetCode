class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
# method(1) 这里可能会导致整数溢出，但是可以AC
        path = n + m - 2
        c = min(n - 1, m - 1)
        res = 1
        for i in range(path, path - c, -1):
            res *= i
        for i in range(1, c + 1):
            res //= i
        return res
# method(2) 更一般的方法
'''
        dp = [[0]*m for i in range(n)]
        if m == 1 or n == 1:
            return 1
        for j in range(n):
            dp[j][0] = 1
        for i in range(m):
            dp[0][i] = 1
        for i in range(1,m):
            for j in range(1,n):
                dp[j][i] = dp[j-1][i]+dp[j][i-1]
        return dp[n-1][m-1]
'''
