class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return 0
        j = 0
        counts = 0
        temp = nums[0]
        for i in range(len(nums)):
            if nums[i] != temp: counts = 0
            if counts < 2:
                nums[j] = nums[i]
                temp = nums[i]
                counts += 1
                j += 1
        return j
