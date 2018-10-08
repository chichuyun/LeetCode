class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
# method(1) 计数排序
        left = 0
        right = len(nums)
        for i in range(len(nums)):
            if nums[i] == 0:
                left += 1
            elif nums[i] == 2:
                right -= 1
        nums[:left]      = [0]*left
        nums[left:right] = [1]*(right-left)
        nums[right:]     = [2]*(len(nums)-right)
# method(2) 一趟扫描
'''
        zero = 0
        two = len(nums)-1
        i = 0
        while i<=two:
            if nums[i] == 1:
                i += 1
            elif nums[i] == 2:
                nums[two], nums[i] = nums[i], nums[two]
                two -= 1
            else:
                nums[zero], nums[i] = nums[i], nums[zero]
                zero += 1
                i += 1
'''
