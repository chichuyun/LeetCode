class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
# method(1) 保存每一位的余数,这里其实就是编译器优化的过程
        if n < 0:
            ans, x, n = 1/x, 1/x, n+1
        elif n == 0:
            return 1.0
        else:
            ans, n = x, n-1
        if n == 0: return x
        num = abs(n)
        rem = []
        counts = 0
        while(num!=1):
            counts += counts
            rem.append(num%2)
            num = num//2
        for index in rem[::-1]:
            ans = (ans)**2*x**index
        return ans*x  # 为了32位整数避免溢出
# method(2) 递归
#        if n < 0:
#            x, n = 1/x, -n
#        if n == 0:
#            return 1
#        if n == 1:
#            return x
#        if n%2 == 0:
#            return self.myPow(x*x, n//2)
#        else:
#            return self.myPow(x*x, n//2)*x
# method(3) 因为编译器有优化,从而这里可以直接返回
#        return x**n
