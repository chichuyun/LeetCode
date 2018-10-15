class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
# method(1) 这种方法看不到顺序,res[:]和res在循环的时候不等价
# 直接赋值是备份,加:就不是备份了
        res = [[]]
        for num in nums :
            for temp in res[:]:
                x = temp.copy()
                x.append(num)
                res.append(x)
        return res
