class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# method (1) 利用异或的性质 b=a^b^a...
        temp = 0
        for x in nums:
            temp ^= x
        return temp
    
# method (2) 利用set求差值
#        return sum(set(nums))*2 - sum(nums)
