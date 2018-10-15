class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
# method(1) 利用hash表进行去重
        res = set([()])
        ans = set([()])
        for num in nums:
            temp = res.copy()
            for L in temp:
                x = list(L)
                x.append(num)
                x.sort()
                res.add(tuple(x))
                ans.add(tuple(x))
        return [list(L) for L in ans]
# method(2) 
'''
        nums.sort()
        res = [[]]
        tmp_size = 0
        for i in range(len(nums)):
            start = tmp_size if i >= 1 and nums[i] == nums[i-1] else 0
            tmp_size = len(res)
            for j in range(start, tmp_size):
                res.append([nums[i]]+res[j])
        return res
'''
