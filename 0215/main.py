class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
# method(1) 之所以这个快，应该是由于python本身效率低的缘故
        return sorted(nums)[-k]
# method(2) 快排
'''
        return self.find(nums, k - 1, 0, len(nums) - 1)
    
    def find(self, nums, k, left, right):
        l = left
        r = right 
        partition = nums[(left + right) // 2]
        while(left <= right):
            while(nums[left] > partition):
                left += 1
            while(nums[right] < partition):
                right -= 1
            if left <= right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
        if right >= k and right > l:
            return self.find(nums, k, l, right)
        if left <= k and left < r:
            return self.find(nums, k, left, r)
        
        return nums[k]
'''
