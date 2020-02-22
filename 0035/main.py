class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

# method(1) 普通二分法,不过要注意right和left更新的顺序
        left = 0
        right = len(nums)
        while(left < right):
            mid = left + (right - left)//2
            print(left, mid, right)
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                right -= 1
            else:
                left += 1
        return left
# method(2) 调用库
#        from bisect import bisect_left
#        return bisect_left(nums, target)
