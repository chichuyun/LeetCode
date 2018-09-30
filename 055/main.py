class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        num = 0
        for x in nums:
            if num == -1:
                return False
            num = max(num-1, x-1)
        return True
