class Solution:
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return 0
        if nums[0] > nums[1]:   # 最左边
            return 0
        if nums[-1] > nums[-2]: # 最右边
            return len(nums)-1
        
        left, right = 0, len(nums)
        while(left < right):
            mid = (left + right)//2
            print(left, mid, right)
            if nums[mid-1] < nums[mid]:
                if nums[mid] > nums[mid+1]:
                    return mid
                else:
                    left = mid + 1
            else:
                right = mid
        return mid
