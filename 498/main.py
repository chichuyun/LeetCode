class Solution:
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        temp = []
        leny = len(matrix)
        lenx = len(matrix[0])
        con = 1
        
        for ij in range(lenx+leny-1):
            for i in range(max(0,ij-leny+1), min(lenx,ij+1))[::con]:
                j = ij - i
                temp.append(matrix[j][i])
            con = -con
        return temp
        
