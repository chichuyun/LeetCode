class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        
        flag = 0
        for i in range(1,length)[::-1]:
            if nums[i-1] < nums[i]:
                j = length - 1
                while j > i - 1:
                    if nums[j] > nums[i-1]:
                        nums[j], nums[i-1] = nums[i-1], nums[j]
                        nums[i:] = nums[length-1:i-1:-1]
                        flag = 1
                        break
                    j -= 1
            if flag == 1: break
        if flag == 0:
            nums.reverse()
            
