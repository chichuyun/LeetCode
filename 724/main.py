class Solution:
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return -1
        elif len(nums)==1:
            return 0
        
        left = 0
        right = sum(nums[1:])
        if(left==right): return 0

        for i in range(1, len(nums)):
            left += nums[i-1]
            right -= nums[i]
            if right == left: return i
        return -1
