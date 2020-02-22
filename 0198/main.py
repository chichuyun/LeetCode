class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# method(1) 类似于多少种路径的问题
        if not nums:
            return 0
        
        for i in range(1,len(nums)-1):
            nums[i+1] += max(nums[max(i-2,0):i])
        
        return max(nums[-3:])
# method(2) 动态规划
'''
        last, now = 0, 0
        for n in nums:
            last, now = now, max(last+n, now)
        return max(last, now)
'''
