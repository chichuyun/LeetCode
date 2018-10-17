class Solution:
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if not triangle: return 0
        
        nums = [triangle[0][0]]
        for L in triangle[1:]:
            temp = list()
            temp.append(nums[0] + L[0])
            for i in range(1,len(nums)):
                temp.append(min(L[i]+nums[i], L[i]+nums[i-1]))
            temp.append(nums[-1] + L[-1])
            nums = temp.copy()
        return min(nums)
