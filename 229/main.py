class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        from collections import Counter
        length = len(nums)//3
        
        L = []
        for i, var in Counter(nums).items():
            if(var>length): L.append(i)
        
        return L
