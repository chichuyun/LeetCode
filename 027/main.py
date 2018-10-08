class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# method(1) 效率高
        if not nums: return 0
        j = 1
        temp = nums[0]
        for i in range(1,len(nums)):
            if nums[i] != temp:
                nums[j] = nums[i]
                temp = nums[i]
                j += 1
        return j

# method(2) 偷懒的方法，并没有用到双指针
'''
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
'''
