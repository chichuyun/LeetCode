class Solution:
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# method(1)
        left = 0
        right = len(nums)-1
        
        if nums[left] <= nums[right]:
            return nums[left]

        while(left<=right):
            mid = (right + left)//2
            if nums[mid] >= nums[right] and nums[mid] <= nums[left]:
                return min(nums[mid], nums[right])
            elif nums[mid] >= nums[right] and nums[mid] >= nums[left]:
                left = mid
            elif nums[mid] <= nums[right] and nums[mid] <= nums[left]:
                right = mid
                
# method(2) 更简洁
'''
        begin = 0
        end = len(nums) - 1
        while begin < end:
            mid = begin + (end - begin) // 2
            if nums[mid] > nums[end]:
                begin = mid + 1
            else:
                end = mid
        return nums[end]
'''
