class Solution:
    def __init__(self):
        self.dic = {'1':1,'2':2}

    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if(str(n) in self.dic):
            return self.dic.get(str(n))
        else:
            self.dic[str(n)] = self.climbStairs(n-1) + self.climbStairs(n-2)
            return self.dic[str(n)]
