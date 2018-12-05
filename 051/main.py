class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
# method(1) 二分法
        nums.sort()
        res = []
        i = 0
        for i in range(len(nums)):
            if i == 0 or nums[i]>nums[i-1]:
                l = i+1
                r = len(nums)-1
                while l < r:
                    s = nums[i] + nums[l] +nums[r]
                    if s == 0:
                        res.append([nums[i],nums[l],nums[r]])
                        l += 1
                        r -= 1
                        while l < r and nums[l] == nums[l-1]:
                            l += 1
                        while r > l and nums[r] == nums[r+1]:
                            r -= 1
                    elif s>0:
                        r -= 1
                    else :
                        l += 1
        return res

# method(2) 会超时
#        if len(nums)<=2: return []
#        from collections import Counter
#        nums.sort()
#        res = list()
#        num_set = Counter(nums)
#        temp1 = None
#        for i, num1 in enumerate(nums):
#            if num1 != temp1:
#                temp1 = num1
#                temp2 = None
#                for num2 in nums[i+1:]:
#                    num3 = - num1 - num2
#                    if num2 != temp2 and num3 >= num2:
#                        temp2 = num2
#                        flag = 0
#                        test = Counter([num1, num2, num3])
#                        for key, v in test.items():
#                            if num_set[key] < v:
#                                flag = 1
#                                break
#                        if flag==0: res.append([num1, num2, num3])
#        return res
