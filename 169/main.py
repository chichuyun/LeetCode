class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# method(1) 利用Counter，值最大的那个
        from collections import Counter
        length = len(nums)//2 if(len(nums)%2==0) else len(nums)//2+1
        for i, var in Counter(nums).items():
            if(var>=length): return i

# method(2) 排序之后，中间那个值肯定是众数
#        nums.sort()
#        return nums[len(nums)//2]
