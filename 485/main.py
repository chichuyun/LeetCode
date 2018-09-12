class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

# method(1) 最一般的放方法
#        index1 = 0
#        index2 = 0
#        temp = 0
#        flag = 0
#        for i, x in enumerate(nums+[0]):
#            if x == 1:
#                if flag == 0:
#                    index1 = i
#                    index2 = i
#                    flag = 1
#                else:
#                    index2 = i
#            elif x == 0:
#                if flag == 1 and index2 - index1 + 1 > temp:
#                    temp = index2 - index1 + 1
#                flag = 0
#        return temp

# method(2) 求和
        temp = 0
        max0 = 0
        for x in nums+[0]:
            if x!=0:
                temp += 1
            else:
                if temp > max0:
                    max0 = temp
                temp = 0
        return max0
        
