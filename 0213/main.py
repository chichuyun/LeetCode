class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        elif len(nums) == 1:
            return nums[0]
        
        return max(self.getNum(nums[1:]), self.getNum(nums[:-1]))
        
    def getNum(self, nums):
        if not nums:
            return 0
        
        for i in range(1,len(nums)-1):
            nums[i+1] += max(nums[max(i-2,0):i])
        
        return max(nums[-3:])
