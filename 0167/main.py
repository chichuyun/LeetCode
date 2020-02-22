class Solution:
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums = dict()
        for i, x in enumerate(numbers):
            if target-x in nums:
                return nums[target-x]+1, i+1
            nums[x] = i
        
