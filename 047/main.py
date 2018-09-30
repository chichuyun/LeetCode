class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
# method(1) 利用set去重
        if not nums: return []
        res = set([()])
        for num, x in enumerate(nums):
            temp = res.copy()
            res = set()
            for L in temp:
                for i in range(num+1):
                    res.add(L[:i]+(x,)+L[i:])
        return [list(L) for L in res]
# method(2) 另一种去重方式
'''
        ans = [[]]
        for n in nums:
            new_ans = []
            for l in ans:
                for i in range(len(l)+1):
                    new_ans.append(l[:i]+[n]+l[i:])
                    if i<len(l) and l[i]==n: break   # 去重复
            ans = new_ans
        return ans
'''
