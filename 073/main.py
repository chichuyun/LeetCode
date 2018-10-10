class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """

        rows, cols = set(), set()
        m, n = len(matrix), len(matrix[0])
        for i, L in enumerate(matrix):
            if 0 in L:
                rows.add(i)
            for j, x in enumerate(matrix[i]):
                if x == 0:
                    cols.add(j)
        for i in range(m):
            if i in rows: matrix[i] = [0]*n
            for j in cols:
                matrix[i][j] = 0
