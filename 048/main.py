class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix) - 1
        length = N//2 + 1
        flag = len(matrix)%2
        for i in range(length):
            for j in range(length-flag):
                matrix[i][j], matrix[j][N-i], matrix[N-i][N-j], matrix[N-j][i] = \
                matrix[N-j][i], matrix[i][j], matrix[j][N-i], matrix[N-i][N-j]
