class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
# method(1) 这里可能会导致整数溢出，有bug，但是似乎必须要调用大整数库
        path = n + m - 2
        c = min(n - 1, m - 1)
        res = 1
        for i in range(path, path - c, -1):
            res *= i
        for i in range(1, c + 1):
            res //= i
        return res
