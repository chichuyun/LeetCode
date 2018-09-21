class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        temp = set()
        
        nums = tuple(map(int,str(n)))
        while(nums not in temp):
            temp.add(nums)
            n = sum([x**2 for x in nums])
            if n==1:
                return True
            nums = tuple(map(int,str(n)))

        return False
