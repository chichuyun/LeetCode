class Solution:
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        max1 = 0
        max2 = 0
        index = 0
        for i, x in enumerate(nums):
            if x>max1:
                max2 = max1
                max1 = x
                index = i
            elif x>max2:
                max2 = x

        if (max1//2)>=max2:
            return index
        else:
            return -1
