class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums: return -1

        left, right = 0, len(nums)-1
        while left <= right:
            mid = (left + right)//2
            if nums[mid] == target:       # 二分查找
                return mid
            if nums[left] <= nums[mid]:   # 左边有序
                if nums[left] <= target <= nums[mid]:  # 最左边
                    right = mid - 1
                else:
                    left = mid + 1
            else:                         # 右边有序
                if nums[mid] <= target <= nums[right]: # 最右边
                    left = mid + 1
                else:
                    right = mid - 1 
        return -1
