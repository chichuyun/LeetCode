class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        num = 0
        counts = 0
        temp = 0
        flag = 0
        for i, x in enumerate(nums):
            num += x
            counts += 1
            if num>=s:
                if flag == 0:
                    temp = counts
                    flag = 1
                con = counts
                for _ in range(con):
                    if num>=s:
                        if counts<temp:
                            temp = counts
                    else:
                        break
                    num -= nums[left]
                    left += 1
                    counts -= 1
        return temp
