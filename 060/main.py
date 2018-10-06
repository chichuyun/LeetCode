class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        nums = list()
        num = 1
        for i in range(1,n):
            num *= i
            nums.append(num)
        nums.reverse()
        
        L = list(range(1,n+1))
        
        k -= 1
        res = ''
        for i in range(n-1):
            div = k//nums[i]
            k = k%nums[i]
            res += str(L[div])
            del L[div]
        res += str(L[0])
        return res
