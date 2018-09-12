class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
# method(1) 偷懒的方法，并没有用到双指针
        counts = nums.count(val)
        for _ in range(counts):
            nums.remove(val)
        return len(nums)
        
