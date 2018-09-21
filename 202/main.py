class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        temp = set()

        while(n not in temp):
            temp.add(n)
            n = sum([int(x)**2 for x in str(n)])
            if n==1:
                return True

        return False
