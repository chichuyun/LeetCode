class Solution:
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
# method (1) 循环求解，这里还可以用递归
        if n <= 0:
            return False
        
        while n%3 == 0:
            n //= 3
        return n == 1

# method (2) 利用最大的3次幂进行求余 3^19
#        return n>=1 and 1162261467%3==0
