class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
# method(1) 自己瞎想的方法,不过效率挺高
        if k == 0: return [[]]
        
        res = list()
        index = [0]*k
        c = -1
        while index[0] < n-k:
            res.append([i+j+1 for j, i in enumerate(index)])
            if index[c] == n-k:   # 最大可能出现的数字
                c -= 1
                while index[c] == n-k:
                    c -= 1
                index[c] += 1
                index[c:] = [index[c]]*(-c)  # 进位
                c = -1
            else:
                index[c] += 1
        res.append(list(range(n-k+1,n+1)))
        return res

# method(2) 库函数,有优化,效率最高
'''
        from itertools import combinations
        return list(combinations(range(1,n+1),k))
'''
# method(3) 最初的代码, 似乎效率比(1)的高
'''
        if k == 0: return [[]]
        
        mat = list()
        for i in range(1,k+1):
            mat.append(range(i,n+1))
        
        res = list()
        index = [0]*k
        c = -1
        while index[0] < n-k:
            res.append([L[i] for i, L in zip(index, mat)])
            if index[c] == n-k:   # 最大可能出现的数字
                c -= 1
                while index[c] == n-k:
                    c -= 1
                index[c] += 1
                index[c:] = [index[c]]*(-c)  # 进位
                c = -1
            else:
                index[c] += 1
        res.append([L[n-k] for L in mat])
        return res
'''
