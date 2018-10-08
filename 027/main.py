class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
# method(1) 效率高
        j = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[j] = nums[i]
                j += 1
        return j
# method(2) 偷懒的方法，并没有用到双指针
'''
        counts = nums.count(val)
        for _ in range(counts):
            nums.remove(val)
        return len(nums)
'''
