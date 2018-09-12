class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if(len(nums)==0): return 0
        temp = nums[0]
        i = 1
        for _ in range(len(nums)-1):
            if(nums[i]==temp):
                del nums[i]
            else:
                temp = nums[i]
                i += 1
        return i
            
