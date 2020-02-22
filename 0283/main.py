class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
# method(1) 效率高
        j = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[j] = nums[i]
                nums[i] = 0
                j += 1

# method(2) 这个没有应用算法特性
'''
        i = len(nums)-1
        j = 0
        for _ in range(len(nums)):
            if(nums[j]!=0):
                j = j + 1
            else:
                del nums[j]
                nums.append(0)
                i -= 1
                if(i==j): break
'''
