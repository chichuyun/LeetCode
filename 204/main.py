class Solution:
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
# method(1) 这里还可以优化
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

#        counts = 0
#        for x in matrix[:n]:
#            if x: counts += 1
#        return counts
# method(2) 大神解法
        if n < 2: return 0
        matrix = [0,0] + [1]*(n-2)
        for i in range(2, int(n**0.5)+1):
            if matrix[i] == 1:
                matrix[i*i:n:i] = [0]*int((n-i*i-1)/i + 1)
        return sum(matrix)
