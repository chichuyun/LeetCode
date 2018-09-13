class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
# method(1) 迭代求平方根,显然自己写的效率不高
        if x==0: return 0
        ans = 2
        temp = 3
        while(abs(ans-temp)>0.5):
            temp = ans
            ans = (ans + x/ans)/2
        return int(ans)
# method(2)
#        import math
#        return int(math.sqrt(x))
