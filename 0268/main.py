class Solution:
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# method(1)
        return sum(range(len(nums)+1)) - sum(nums)
# method(2) 利用通项公式
'''
        n = len(nums)
        return n*(n + 1)//2 - sum(nums)
'''
