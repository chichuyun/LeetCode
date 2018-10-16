class Solution:
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
# method(1) 类似3的幂解法
        return n > 0 and 2147483648%n == 0
# method(2) 位与,2的二进制码只有一个1
'''
        if n == 0:
            return False
        else:
            return n & (n - 1) == 0
'''
