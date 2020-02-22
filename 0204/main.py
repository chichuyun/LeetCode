class Solution:
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
# method(1) 这里还可以优化(置零那里)
        if(n<=2): return 0
        matrix = [False,False,True] + (n-2)*[True]
        x = 0
        while((x+1)*(x+1)<=n):
            x += 1
            if matrix[x]==0: continue
            num = x*x
            while(num<=n):
                matrix[num] = False
                num += x
        return sum(matrix[:n])

# method(2) 大神解法(其中置零用隐形循环)
#        if n < 2: return 0
#        matrix = [0,0] + [1]*(n-2)
#        for x in range(2, int(n**0.5)+1):
#            if matrix[x] == 1:
#                matrix[x*x:n:x] = [0]*int((n-x*x-1)/x + 1)
#        return sum(matrix)

# method(3) 乘法(效率最低)
#        if(n<=2): return 0
#        matrix = [False,False,True] + (n-2)*[True]
#        x = 0
#        while((x+1)*(x+1)<=n):
#            x += 1
#            if matrix[x]==0: continue
#            for y in range(x,n//x+1):
#                num = x*y
#                while(num<=n):
#                    matrix[num] = False
#                    num *= x
#        return sum(matrix[:n])
