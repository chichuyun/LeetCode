class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        temp = 0
        total = nums[0]
        for x in nums:

            if temp < 0:
                temp = 0
            temp += x

            if(temp > total):
                total = temp

        return total
