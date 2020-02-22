class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        res = [[]]
        for num, x in enumerate(nums):
            temp = res.copy()
            res = list()
            for L in temp:
                res = [L[:i]+[x]+L[i:] for i in range(num+1)]
        return res
