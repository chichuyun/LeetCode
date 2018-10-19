class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
# method(1) 二分查找
        left, right = 0, x
        while(left < right):
            mid = left + (right - left)//2
            if mid*mid <= x < (mid+1)*(mid+1) :
                return mid
            elif mid*mid < x:
                left = mid + 1
            else:
                right = mid - 1
        return -1
# method(2) 迭代求平方根,显然自己写的效率不高
'''
        if x==0: return 0
        ans = 2
        temp = 3
        while(abs(ans-temp)>0.5):
            temp = ans
            ans = (ans + x/ans)/2
        return int(ans)
'''
# method(3)
#        import math
#        return int(math.sqrt(x))
