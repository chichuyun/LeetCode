class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums)==0: return -1

        left = 0
        right = len(nums) - 1
        while(left<=right):
            mid = (right + left)//2
            if nums[mid]==target:
                return mid
            if nums[left]<=nums[mid]:
                if nums[left]<=target and target<nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            if nums[mid]<=nums[right]:
                if nums[mid]<target and target<=nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1
