class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
# method(1) 先输出格雷编码,再转换为数字
        if n == 0: return [0]
        
        nums = [2**i for i in range(n)]
        
        Codes = [[0],[1]]
        for _ in range(n-1):
            temp = Codes.copy()
            Codes = list()
            for L in temp:
                Codes.append([0] + L)
            for L in temp[::-1]:
                Codes.append([1] + L)
        
        res = list()
        for L in Codes:
            num = 0
            for i in range(n):
                num += nums[i]*L[-i-1]
            res.append(num)
        return res

# method(2) 直接计算数值,思路和method(1)一样
'''
        res = [0]
        for i in range(n):
            res += [x + pow(2, i) for x in reversed(res)]
# method(3) 大神解法
        return [i ^ (i >> 1) for i in range(1 << n)]
'''
