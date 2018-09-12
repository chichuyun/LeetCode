class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
# method (1) 暴力解法
#        for i in range(len(nums)):
#        for j in range(i+1, len(nums)):
#             if nums[j]+nums[i] == target:
#                 return [i, j]
        
# method (2) 刚开就就创建整个dict
#        if(len(nums)<=1): return
#        dic = {str(x):[] for x in set(nums)}
#        for i, var in enumerate(nums):
#            dic[str(var)].append(i)
#        for var1, index1 in dic.items():
#            index2 = dic.get(str(target-int(var1)))
#            if(index2!=None):
#                if(int(var1)!=target-int(var1)):
#                    return [index1[0], index2[0]]
#                else:
#                    if(len(index1)<=1): continue
#                    return [index1[0], index2[1]]

# method(3) 动态创建dict
        dic = {}
        for i, num in enumerate(nums):
            if (target - num) in dic:
                return i, dic[target - num]
            dic[num] = i
